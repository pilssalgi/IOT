#include <DHT11.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

int pin = 13;    // 연결한 아두이노 디지털 핀 번호
DHT11 dht11(pin); 

LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
   Serial.begin(9600);
   pinMode(LED_BUILTIN, OUTPUT);pinMode(LED_BUILTIN, OUTPUT);
//   lcd.init();
//   lcd.backlight();
}

void loop()
{
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a seconddigitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)

  int err;
  float temp, humi;
//  float t = dht11.readTemperature();

  if((err=dht11.read(humi, temp))==0){
    Serial.print(" temperature:");
    Serial.print(temp);
    Serial.print(" humidity:");
    Serial.print(humi);
    Serial.println();

//    lcd.clear();
//    lcd.setCursor(0,0);
//    lcd.print("Temp = ");
//    lcd.print(temp);
//    lcd.setCursor(0,1);
//    lcd.print("Humi = ");
//    lcd.print(humi);
  }else{
    Serial.println();
    Serial.print("Error No :");
    Serial.print(err);
    Serial.println();
  }
  delay(1000); //delay for rereadint err;
}
