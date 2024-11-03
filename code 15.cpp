#include <LiquidCrystal.h>

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

byte armsDown[8] = {    // ساختن کاراکتر آدمک با دستان پایین
  0b00100,
  0b01010,
  0b00100,
  0b00100,
  0b01110,
  0b10101,
  0b00100,
  0b01010
};

byte armsUp[8] = {      // ساختن کاراکتر آدمک با دستان بالا
  0b00100,
  0b01010,
  0b00100,
  0b10101,
  0b01110,
  0b00100,
  0b00100,
  0b01010
};

void setup() {
  lcd.begin(16, 2);
  lcd.createChar(3, armsDown);  // ست کردن شماره ای برای هر کدام از دو کاراکتر
  lcd.createChar(4, armsUp);
}

void loop() {
  for (int i = 0; i < 16; i++) {    // حرکت آدمک در ردیف اول
    if (i % 2 == 0) {   // در ستون های 0 ، 2 ، 4 و غیره کاراکتر آدمک دست پایین خواهد بود
      lcd.setCursor(i, 0);
           lcd.write(3);
      } else {
        lcd.setCursor(i, 0);    // در ستون های 1 ، 3 ، 5 و غیره کاراکتر آدمک دست بالا خواهد بود
             lcd.write(4);
        }
        delay(500);
        lcd.clear();    // در انتهای هر بار جایگذاری کاراکتر، صفحه پاک می شود تا حالت متحرک داشته باشد
    }

    for (int i = 15; i > -1; i--) {     // در ردیف دوم حرکت آدمک از آخرین ستون شروع شده و اولین ستون خواهد رسید
    if (i % 2 == 0) {
      lcd.setCursor(i, 1);
      lcd.write(3);
      } else {
        lcd.setCursor(i, 1);
        lcd.write(4);
        }
        delay(500);
        lcd.clear();
    }
}