#include "inc/tm4c123gh6pm.h"
#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/gpio.c"
#include "inc/hw_gpio.h"
#include "driverlib/sysctl.c"
#include "lcd.h"
#include "driverlib/timer.h"
#include "driverlib/interrupt.h"

void otuzhexgonder()
{
    SysCtlDelay(100000);
    // rs=0
    GPIOPinWrite(LCDPORT, RS, 0);
    //ayar yaz�ld�
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, 0X30);
    // en ac kapa
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);
    // 3 kez 30h g�nder
}

void lcdkomut(unsigned char c) //0x47
{
    GPIOPinWrite(LCDPORT, RS, 0);
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, (c & 0xf0));
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);

    SysCtlDelay(1000);

    GPIOPinWrite(LCDPORT, RS, 0);
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, (c & 0x0f)<<4);
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);

    SysCtlDelay(1000);

}

void LCDilkayarlar()
{
    //portf_base_enable
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);
    GPIOPinTypeGPIOOutput(LCDPORT, 0xFF); // hepsi out

    otuzhexgonder();
    otuzhexgonder();
    otuzhexgonder();

    // ayarlar devam
    //lcd komut kullan
    lcdkomut(0x0f); // ekrani ac-kapa
    SysCtlDelay(6000);
    lcdkomut(0x01); // ekrani sil
    SysCtlDelay(6000);
    lcdkomut(0x06); // giris kipi
    SysCtlDelay(6000);
    lcdkomut(0x02); // kurs�r basa don
    SysCtlDelay(6000);
    lcdkomut(0x18); // kurs�r kaydir
    SysCtlDelay(6000);
}

void lcdfonksiyonayarla( unsigned char e)
{
    SysCtlDelay(2000);
    GPIOPinWrite(LCDPORT, RS, 0);
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, (e & 0xf0));
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(2000);
    GPIOPinWrite(LCDPORT, E, 0);

    SysCtlDelay(2000);

    GPIOPinWrite(LCDPORT, RS, 0);
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, (e & 0x0f)<<4);
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(2000);
    GPIOPinWrite(LCDPORT, E, 0);

    SysCtlDelay(2000);

}


void lcdkarakteryaz(unsigned char d)
{
    GPIOPinWrite(LCDPORT, RS, 1); // Karakter yazma modu
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (d & 0xF0));
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);

    SysCtlDelay(1000);

    GPIOPinWrite(LCDPORT, RS, 1); // Karakter yazma modu
    GPIOPinWrite(LCDPORT, D4 | D5 | D6 | D7, (d & 0x0F) << 4);
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);

    SysCtlDelay(1000);

}


void LCDgit(unsigned char k,unsigned char m) // gidilecek sat�r-sut�n
{
    unsigned char address;

    if (k ==0) address = 0x80 + m; // 1. Sat�r
    else if (k == 1) address = 0xC0 + m; // 2. Sat�r


    lcdkomut(address); // �mleci belirli konuma g�t�rme komutu
}

void LCDTemizle(){
    GPIOPinWrite(LCDPORT, RS, 0);
    SysCtlDelay(2000);
    lcdkomut(0x01);

}



