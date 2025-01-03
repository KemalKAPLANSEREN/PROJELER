#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_types.h"
#include "inc/hw_memmap.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "lcd.h"

void otuzhexgonder() {
    SysCtlDelay(100000);
    // rs=0
    GPIOPinWrite(LCDPORT, RS, 0);
    //ayar yazýldý
    GPIOPinWrite(LCDPORT, D4|D5|D6|D7, 0X30);
    // en ac kapa
    GPIOPinWrite(LCDPORT, E, 2);
    SysCtlDelay(1000);
    GPIOPinWrite(LCDPORT, E, 0);
    // 3 kez 30h gönder
}

void lcdkomut(unsigned char c) {
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

void lcdkarakteryaz(unsigned char d) {
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

void LCDilkayarlar() {
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); // PortB etkinleþtir
    GPIOPinTypeGPIOOutput(LCDPORT, RS | E | D4 | D5 | D6 | D7); // Pinleri çýkýþ yap

    // Önceki verilerden kalan olasý artýklarý temizlemek için tüm pinleri sýfýrla
    GPIOPinWrite(LCDPORT, RS | E | D4 | D5 | D6 | D7, 0x00); // Tüm pinleri LOW yap
    SysCtlDelay(50000);  // LCD’nin baþlatýlmasý için gecikme

    // 4-bit mod baþlatmak için üç kez 0x30 komutu gönder
    otuzhexgonder();
    SysCtlDelay(50000);
    otuzhexgonder();
    SysCtlDelay(50000);
    otuzhexgonder();
    SysCtlDelay(50000);

    // 4-bit moda geçiþ komutu
    lcdkomut(0x02); // LCD'yi 4-bit modda baþlat
    SysCtlDelay(50000);

    // LCD ayar komutlarý
    lcdkomut(0x28); // 2 satýr, 5x7 karakter
    SysCtlDelay(50000);
    lcdkomut(0x0C); // Ekran açýk, imleç kapalý
    SysCtlDelay(50000);
    lcdkomut(0x06); // Ýmleci saða kaydýr
    SysCtlDelay(50000);

    // Ekraný temizle
    LCDTemizle();
    SysCtlDelay(50000);
}

void LCDTemizle() {
    lcdkomut(0x01); // Ekraný temizle komutu
    SysCtlDelay(2000);
}

void LCDgit(unsigned char x, unsigned char y) {
    unsigned char address;
    if (x == 0) {
        address = y;
    } else {
        address = 0x40 + y;
    }
    lcdkomut(0x80 | address);
}

void lcdyaz(const char *str) {
    while (*str) {
        lcdkarakteryaz(*str++);
    }
}

// LCD'ye sayýsal bir deðeri yazdýrmak için fonksiyon
void lcdSayiyaz(int value) {
    char buffer[16]; // Sayýyý yazmak için buffer
    sprintf(buffer, "%d", value); // Sayýyý stringe çevir
    lcdyaz(buffer); // Stringi LCD'ye yaz
}
