#include <Servo.h>
Servo servo;
int servoPin = 9;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(servoPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  int angle = map(sensorValue,0,1023,0,180);
  servo.write(angle);

  Serial.println(sensorValue);
  Serial.println(angle);
  delay(100);
}

