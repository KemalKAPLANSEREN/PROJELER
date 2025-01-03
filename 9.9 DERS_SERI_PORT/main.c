#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"
#include "driverlib/uart.h"
#include "driverlib/uart.c"
#include "driverlib/pin_map.h"
#include "driverlib/adc.h"

#define RS GPIO_PIN_0
#define E  GPIO_PIN_1
#define D4 GPIO_PIN_4
#define D5 GPIO_PIN_5
#define D6 GPIO_PIN_6
#define D7 GPIO_PIN_7

void SetInitSettings();
void timerkesmefonksiyonu();
void delayMs(int n);
void lcd_command(unsigned char command);
void lcd_data(unsigned char data);
void lcd_init(void);
void lcd_print(char *str);
void format_time(char *buffer, int saat, int dakika, int saniye);

void uart_ayari();
void diger_ayar();
void serikesme();

// Zaman de�i�kenleri (kesme fonksiyonu i�in volatile)
int saat;
int dakika;
int saniye;
int temp=0;
int main(void)
{
    lcd_init();          // LCD'yi ba�lat
    SetInitSettings();   // Timer ve kesmeleri ayarla
    uart_ayari();
    diger_ayar();

    while (1)
    {       ADCIntClear(ADC0_BASE, 1);
    ADCProcessorTrigger(ADC0_BASE, 1);
    while(!ADCIntStatus(ADC0_BASE, 1, false)){}
    uint32_t gelendata[4];
    ADCSequenceDataGet(ADC0_BASE, 1, gelendata);
    uint32_t ortalamadeger=(gelendata[0]+gelendata[1]+gelendata[2]+gelendata[3])/4;
    temp=(ortalamadeger * 3.3 / 4096.0) * 100.0;
    ADCIntClear(ADC0_BASE, 1);

    }
}

void SetInitSettings()
{
    SysCtlClockSet(SYSCTL_SYSDIV_5 | SYSCTL_USE_PLL | SYSCTL_XTAL_16MHZ | SYSCTL_OSC_MAIN); // 40 MHz

    // GPIO ayarlar�
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3); // PF1, PF2, PF3 ��k��

    // Timer ayarlar�
    SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
    TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC); // Periyodik mod
    TimerLoadSet(TIMER0_BASE, TIMER_A, SysCtlClockGet()); // 40 MHz -> 1 saniye

    // Kesme ayarlar�
    IntMasterEnable();                             // Genel kesmeleri a�
    IntEnable(INT_TIMER0A);                        // Timer0A kesmesini etkinle�tir
    TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT); // Kesme kayna��n� se�
    TimerIntRegister(TIMER0_BASE, TIMER_A, timerkesmefonksiyonu); // Kesme i�leyicisini kaydet
    //TimerEnable(TIMER0_BASE, TIMER_A);             // Timer'� ba�lat
    //ADC Ayarlar�
    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0); // ADC HAYAT=1
    ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0); /// adc0 kullan ve sequence 1 se�

    ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_CH0);
    ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_CH0);
    ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_CH0);
    ADCSequenceStepConfigure(ADC0_BASE, 1, 3, ADC_CTL_CH0|ADC_CTL_IE|ADC_CTL_END);
    ADCSequenceEnable(ADC0_BASE, 1);



}

// Kesme i�leyicisi
void timerkesmefonksiyonu()
{
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT); // Kesme bayra��n� temizle

    // Zaman� g�ncelle
    saniye++;
    if (saniye == 60) {
        saniye = 0;
        dakika++;
    }
    if (dakika == 60) {
        dakika = 0;
        saat++;
    }
    if (saat == 24) {
        saat = 0;
    }

    // Zaman� string format�nda UART �zerinden g�nder
    char buffer2[9]; // "HH:MM:SS" i�in yer ay�r
    format_time(buffer2, saat, dakika, saniye); // Formatlanm�� zaman� olu�tur
    int i;
    for (i = 0; i < 8; i++) {
        UARTCharPut(UART0_BASE, buffer2[i]);
    }

    // Zaman� LCD'ye yazd�r
    lcd_command(0xC8); // 2. sat�ra git
    lcd_print(buffer2);
}

// LCD ba�latma
void lcd_init() {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    while (!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOB));

    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, (RS | E | D4 | D5 | D6 | D7));

    delayMs(20);
    lcd_command(0x03);
    delayMs(5);
    lcd_command(0x03);
    delayMs(5);
    lcd_command(0x03);
    delayMs(1);
    lcd_command(0x02);
    delayMs(1);

    lcd_command(0x28); // 4-bit mod, 2 sat�r
    delayMs(1);
    lcd_command(0x0C); // Ekran� a�, imle� kapal�
    delayMs(1);
    lcd_command(0x06); // Yazma y�n� sa�a
    delayMs(1);
    lcd_command(0x01); // Ekran� temizle
    delayMs(2);
}

// LCD komut g�nderme
void lcd_command(unsigned char command) {

    GPIOPinWrite(GPIO_PORTB_BASE, D4 | D5 | D6 | D7, (command & 0xF0));
    GPIOPinWrite(GPIO_PORTB_BASE, RS, 0);
    GPIOPinWrite(GPIO_PORTB_BASE, E, E);
    delayMs(2);
    GPIOPinWrite(GPIO_PORTB_BASE, E, 0);

    GPIOPinWrite(GPIO_PORTB_BASE, D4 | D5 | D6 | D7, (command << 4));
    GPIOPinWrite(GPIO_PORTB_BASE, RS, 0);
    GPIOPinWrite(GPIO_PORTB_BASE, E, E);
    delayMs(2);
    GPIOPinWrite(GPIO_PORTB_BASE, E, 0);
}

// LCD veri g�nderme
void lcd_data(unsigned char data) {
    GPIOPinWrite(GPIO_PORTB_BASE, D4 | D5 | D6 | D7, (data & 0xF0));
    GPIOPinWrite(GPIO_PORTB_BASE, RS, RS);
    GPIOPinWrite(GPIO_PORTB_BASE, E, E);
    delayMs(2);
    GPIOPinWrite(GPIO_PORTB_BASE, E, 0);

    GPIOPinWrite(GPIO_PORTB_BASE, D4 | D5 | D6 | D7, (data << 4));
    GPIOPinWrite(GPIO_PORTB_BASE, RS, RS);
    GPIOPinWrite(GPIO_PORTB_BASE, E, E);
    delayMs(2);
    GPIOPinWrite(GPIO_PORTB_BASE, E, 0);
}

// LCD'ye string yazd�rma
void lcd_print(char *str) {
    while (*str) {
        lcd_data(*str++);
    }
}

// Zaman� formatlama
void format_time(char *buffer, int saat, int dakika, int saniye) {
    buffer[0] = '0' + (saat / 10);
    buffer[1] = '0' + (saat % 10);
    buffer[2] = ':';
    buffer[3] = '0' + (dakika / 10);
    buffer[4] = '0' + (dakika % 10);
    buffer[5] = ':';
    buffer[6] = '0' + (saniye / 10);
    buffer[7] = '0' + (saniye % 10);
    buffer[8] = '\0';
}

// Gecikme fonksiyonu
void delayMs(int n)
{
    SysCtlDelay((n * SysCtlClockGet()) / 3000);
}

void uart_ayari()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);

    // pin ayarlar�
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, 255);
    GPIOPinConfigure(GPIO_PA0_U0RX);
    GPIOPinConfigure(GPIO_PA1_U0TX);
    GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);

    // UART0 yap�land�r
    UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 9600, // Baud rate: 9600
                        (UART_CONFIG_WLEN_8 |               // 8-bit veri uzunlu�u
                         UART_CONFIG_STOP_ONE |             // 1 stop biti
                         UART_CONFIG_PAR_NONE));

}

void diger_ayar()
{
    IntEnable(INT_UART0);
    UARTIntEnable(UART0_BASE, UART_INT_RX|UART_INT_RT);
    UARTIntClear(UART0_BASE, UART_INT_RX|UART_INT_RT);
    UARTIntRegister(UART0_BASE, serikesme);
}

void serikesme()
{
    char buffer[9];  // "HH:MM:SS" i�in 8 karakter + null terminator
    int i = 0;

    // UART �zerinden 8 karakter oku
    while (i < 8) {
        buffer[i] = UARTCharGet(UART0_BASE);
        i++;
    }
    buffer[8] = '\0'; // String'i sonland�r

    // "HH:MM:SS" format�ndaki string'i par�ala
    saat   = (buffer[0] - '0') * 10 + (buffer[1] - '0');
    dakika = (buffer[3] - '0') * 10 + (buffer[4] - '0');
    saniye = (buffer[6] - '0') * 10 + (buffer[7] - '0');

    TimerEnable(TIMER0_BASE, TIMER_A);
}
