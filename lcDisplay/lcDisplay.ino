#include <LiquidCrystal.h>
#include <string.h>

#define numRows 2
#define numCols 16

const int RS = 8, E = 9, D4 = 4, D5 = 5, D6 = 6, D7 = 7;
LiquidCrystal lcd(RS, E, D4, D5, D6, D7);


void setup() {
  Serial.begin(9600);
  lcd.begin(numRows, numCols);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("   This is a");
  lcd.setCursor(0, 1);
  lcd.print("Spartan Display");
  lcd.noCursor();
}

void loop() {
  if (Serial.available() > 0) {
    String text = Serial.readString();
    lcd.clear();
    lcd.home();
    int i = 0;
//    int l = text.size();
    
    for (int  thisRow = 0; thisRow < numRows; thisRow++) {
      for (int thisCol = 0; thisCol < numCols; thisCol++) {
        lcd.setCursor(thisCol, thisRow);
        if (text[i] != '\0') {
          if(text[i] == '#') {
            thisRow += 1;
            thisCol = 0;
          } else {
            lcd.write(text[i]);
          }
          i += 1;
        } else {
          lcd.write(" ");
        }
        delay(200);
      }
    }
  }
}
