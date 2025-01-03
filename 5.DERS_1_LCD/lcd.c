/*
 * lcd.c
 *
 *  Created on: 3 Kas 2024
 *      Author: ABRA A5 V16.6.1
 */
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

void otuzhexgonder()
{
    SysCtlDelay(100);
     GPIOPinWrite(GPIO_PORTB_BASE, RS , 0);
     // ayar yazýldý
     GPIOPinWrite(GPIO_PORTB_BASE, D4|D5|D6|D7, 0x30);
     //enable aç kapa
     GPIOPinWrite(GPIO_PORTB_BASE, E, 2);
     SysCtlDelay(100);
     GPIOPinWrite(GPIO_PORTB_BASE, E, 0);
     //30h gönderildi

}

void lcdkomut (unsigned char c) //0x47 c=41H ise swaplayarak 4 bit halinde gönder.
{

    GPIOPinWrite(GPIO_PORTB_BASE, RS, 0);
    GPIOPinWrite(GPIO_PORTB_BASE, D4|D5|D6|D7, (c & 0xF0));
    GPIOPinWrite(GPIO_PORTB_BASE, E, 2);
    SysCtlDelay(100);

    GPIOPinWrite(GPIO_PORTB_BASE, E, 0);



    GPIOPinWrite(GPIO_PORTB_BASE, RS, 0);
    GPIOPinWrite(GPIO_PORTB_BASE, D4|D5|D6|D7, (c & 0x0F)<<4); // sonra 4 bit kaydýrdýk.
    GPIOPinWrite(GPIO_PORTB_BASE, E, 2);
    SysCtlDelay(100);
    GPIOPinWrite(GPIO_PORTB_BASE, E, 0);

    SysCtlDelay(100);
}


void lcdilkayar()
{

    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);// port b aktif , kitli pin yok
    GPIOPinTypeGPIOOutput(GPIO_PORTB_BASE, 0xFF); //hepsi output

  //  SysCtlDelay(100000);

    otuzhexgonder();
    otuzhexgonder();
    otuzhexgonder();
    lcdkomut(0x02);

    // ayarlar komut
    //lcd komut
}

void lcdfonksiyonayarla(unsigned char DL,unsigned char N,unsigned char F )
{


//        if DL
//
//        if N
//
//        if F
        unsigned char cmd = 0x20; // Fonksiyon set komutu baþlangýcý

        if (DL)cmd |= 0x10; // DL: Data Length (0 = 4-bit, 1 = 8-bit)
        if (N) cmd |= 0x08;  // N: Display lines (0 = 1 satýr, 1 = 2 satýr)
        if (F) cmd |= 0x04;  // F: Font (0 = 5x8, 1 = 5x10)

        lcdkomut(cmd); // Fonksiyon set komutunu gönder

}

void lcdkarakteryaz(unsigned char c)
{


    GPIOPinWrite(GPIO_PORTB_BASE, RS,1);
    GPIOPinWrite(GPIO_PORTB_BASE, D4|D5|D6|D7, (c & 0xF0));
    GPIOPinWrite(GPIO_PORTB_BASE, E, 2);
    SysCtlDelay(100);
    GPIOPinWrite(GPIO_PORTB_BASE, E, 0);
    SysCtlDelay(100);



    GPIOPinWrite(GPIO_PORTB_BASE, RS, 1);
    GPIOPinWrite(GPIO_PORTB_BASE, D4|D5|D6|D7, (c & 0x0F)<<4);
    GPIOPinWrite(GPIO_PORTB_BASE, E, 2);
    SysCtlDelay(100);
    GPIOPinWrite(GPIO_PORTB_BASE, E, 0);
    SysCtlDelay(100);

}

void LCDTemizle()
{
     lcdkomut(0x01);
    SysCtlDelay(100);
}


void LCDgit(unsigned char k,unsigned char m) // gidilecek satýr-sutün
{
    unsigned char address;

    if (k == 0) address = 0x80 + m; // 1. Satýr
    else if (k == 1) address = 0xC0 + m; // 2. Satýr


    lcdkomut(address); // Ýmleci belirli konuma götürme komutu
}



