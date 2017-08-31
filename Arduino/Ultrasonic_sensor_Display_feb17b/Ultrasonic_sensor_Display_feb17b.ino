#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  lcd.init();
  lcd.backlight();
}

void loop() {
  // put your main code here, to run repeatedly:
  int duration,cm;

  digitalWrite(2,HIGH); // 센서에 Trig 신호 입력
  delayMicroseconds(10); // 10us 정도 유지
  digitalWrite(2,LOW); // Trig 신호 off

  duration = pulseIn(3,HIGH);
  cm = microsecondsToCentimeters(duration);

  Serial.print(cm);
  Serial.println("cm");

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Distance = ");
  lcd.print(cm);
  lcd.print("cm");
  lcd.noCursor();

  

  delay(1000);
}

int microsecondsToCentimeters(int microseconds){
  return microseconds / 29 / 2;
}

