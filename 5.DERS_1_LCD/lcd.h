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

void lcdkomut(unsigned char c); // 0 la 255 arsýnda veri
//rs =0
//d4-d7 arasýnda veri yaz
//en enable aç kapa
void lcdilkayar();
//giriþ kipini seç
//ekran aç/kapa
//kürsor kaydýr

void lcdkarakteryaz(unsigned char  );
//rs=1
//d4-d7 arasýnda veri yaz
//en enable aç kapa
void lcdfonksiyonayarla(unsigned char DL, unsigned char N,unsigned char F);// DL,N,F
//b=0 is e4 bit ayralarsýn
//b=1 ise 8 bit ayarlansýn  þeklinde fonskiyon oluþturduk. fonksiyo seçtik
// 4 bit  bit ayarla
//rs=1
//d4-d7 arasýnda veri yaz
//en enable aç kapa
void LCDTemizle();
//rs=0
//d4-d7 arasýnda veri yaz
//en enable aç kapa

void LCDgit(unsigned char,unsigned char);
//satýr ve sütüna git
//1satýr, 1 sutüna git


#endif //lcd_h/

