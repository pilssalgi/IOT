#include <Servo.h>
#include <SoftwareSerial.h>

#define BT_TXD 2
#define BT_RXD 3

int servoPin = 8;
int angle = 0;
Servo servo;
SoftwareSerial BTSerial(BT_TXD,BT_RXD);
boolean temp = 0;


void setup() {
  // put your setup code here, to run once:
  int speed = 9600;
  servo.attach(servoPin);
  Serial.begin(speed);
  BTSerial.begin(speed);
}

void loop() {
  // put your main code here, to run repeatedly:
  byte data;
  if(BTSerial.available()){
    data = BTSerial.read();
    Serial.write(data);
//    Serial.println(data == "a");
    if(data == '1'){
      digitalWrite(13, HIGH);
//      Serial.println("on");
      angle = 0;
    }else{
      digitalWrite(13, LOW);
//      Serial.println("off");
      angle = 180;
    }
  }

  if(Serial.available()){
    BTSerial.write(Serial.read());
    
  }

//  angle++;
//  if(angle>180)angle = 0;


  servo.write(angle);
//  if(data == '0'){
//    Serial.println("off");
//  }
//
//  if(data == '1'){
//    Serial.println("on");
//  }
}
