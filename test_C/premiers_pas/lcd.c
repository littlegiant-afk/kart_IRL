#include <wiringPiI2C.h>
#include <wiringPi.h>
#include <stdio.h>
#include <string.h>

#define LCD_CHR  1  // Mode Data
#define LCD_CMD  0  // Mode Command

#define LCD_LINE_1 0x80
#define LCD_LINE_2 0xC0

#define LCD_BACKLIGHT 0x08

#define ENABLE 0b00000100

int lcd_fd;

void lcd_toggle_enable(int bits) {
    delayMicroseconds(500);
    wiringPiI2CWrite(lcd_fd, bits | ENABLE);
    delayMicroseconds(500);
    wiringPiI2CWrite(lcd_fd, bits & ~ENABLE);
    delayMicroseconds(500);
}

void lcd_byte(int bits, int mode) {
    int high = mode | (bits & 0xF0) | LCD_BACKLIGHT;
    int low  = mode | ((bits << 4) & 0xF0) | LCD_BACKLIGHT;

    wiringPiI2CWrite(lcd_fd, high);
    lcd_toggle_enable(high);
    wiringPiI2CWrite(lcd_fd, low);
    lcd_toggle_enable(low);
}

void lcd_init() {
    lcd_byte(0x33, LCD_CMD); // Init
    lcd_byte(0x32, LCD_CMD);
    lcd_byte(0x06, LCD_CMD); // Increment cursor
    lcd_byte(0x0C, LCD_CMD); // Display ON, cursor OFF
    lcd_byte(0x28, LCD_CMD); // 4-bit mode, 2 lines
    lcd_byte(0x01, LCD_CMD); // Clear
    delay(5);
}

void lcd_write(const char *text, int line) {
    lcd_byte(line, LCD_CMD);
    for (int i = 0; i < strlen(text); i++) {
        lcd_byte(text[i], LCD_CHR);
    }
}

int main() {
    // Adresse I2C de ton LCD (ex: 0x27 ou 0x3F)
    lcd_fd = wiringPiI2CSetup(0x27);

    if (lcd_fd < 0) {
        printf("Erreur : LCD non détecté !\n");
        return -1;
    }

    lcd_init();
	
	delay(5000);
	
    lcd_write("Tu pues", LCD_LINE_1);
    lcd_write("Ton gros cul", LCD_LINE_2);

    delay(5000);

    lcd_byte(0x01, LCD_CMD); // Clear screen

    lcd_write("Tu peux", LCD_LINE_1);
    lcd_write("me branler ?", LCD_LINE_2);

    return 0;
}
