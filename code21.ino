#include <LiquidCrystal.h>

int btn1 = 1;
int btn2 = 2;

int xPosition = 0;
int yPosition = 0;

int boxA = map(x, 1, 50, 50, 1);
int boxB = map(x, 1, 50, 50, 1);
int boxC = map(x, 1, 50, 50, 1);
int boxD = map(x, 1, 50, 50, 1);
int boxE = map(x, 1, 50, 50, 1);
int boxF = map(x, 1, 50, 50, 1);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.print("Welcome!");
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.noDisplay();
  delay(500);
  lcd.display();
  delay(500);

  for (int 
}
