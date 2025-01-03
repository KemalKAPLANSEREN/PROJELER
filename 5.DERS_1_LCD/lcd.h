/*
 * lcd.h
 *
 *  Created on: 3 Kas 2024
 *      Author: ABRA A5 V16.6.1
 */

#ifndef LCD_H_
#define LCD_H_



#define LCDPORT             GPIO_PORTB_BASE
#define LCDPORTENABLE       SYSCTL_PERIPH_GPIOB
#define RS                  GPIO_PIN_0
#define E                   GPIO_PIN_1
#define D4                  GPIO_PIN_4//lcd db4=pb4


#define D5                  GPIO_PIN_5//lcd db5=pb5

#define D6                  GPIO_PIN_6//lcd db6=pb6

#define D7                  GPIO_PIN_7 //lcd db7=pb7

void lcdkomut(unsigned char c); // 0 la 255 ars�nda veri
//rs =0
//d4-d7 aras�nda veri yaz
//en enable a� kapa
void lcdilkayar();
//giri� kipini se�
//ekran a�/kapa
//k�rsor kayd�r

void lcdkarakteryaz(unsigned char  );
//rs=1
//d4-d7 aras�nda veri yaz
//en enable a� kapa
void lcdfonksiyonayarla(unsigned char DL, unsigned char N,unsigned char F);// DL,N,F
//b=0 is e4 bit ayralars�n
//b=1 ise 8 bit ayarlans�n  �eklinde fonskiyon olu�turduk. fonksiyo se�tik
// 4 bit  bit ayarla
//rs=1
//d4-d7 aras�nda veri yaz
//en enable a� kapa
void LCDTemizle();
//rs=0
//d4-d7 aras�nda veri yaz
//en enable a� kapa

void LCDgit(unsigned char,unsigned char);
//sat�r ve s�t�na git
//1sat�r, 1 sut�na git


#endif //lcd_h/

