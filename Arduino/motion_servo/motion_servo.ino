#include <Servo.h>
Servo servo;
int servoPin = 9;
int inputPin = 2;
int ledPin = 13;
int pirState = LOW;
int angle = 0;
int cnt = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin,OUTPUT);
  pinMode(inputPin,INPUT);
  servo.attach(servoPin);
  Serial.begin(9600);
}


void loop() {
  // put your main code here, to run repeatedly:
  int motion= digitalRead(inputPin);
  unsigned long crtTime = millis();

  if (motion == HIGH) { // 인체감지시
    digitalWrite(ledPin, HIGH); // LED ON
    if (pirState == LOW) {
    // 시리얼모니터에 메시지 출력
    Serial.println("Motion detected!");
    pirState = HIGH;
    }
  } else {
      digitalWrite(ledPin, LOW); // LED OFF
      if (pirState == HIGH){        
          // 시리얼모니터에 메시지 출력            
          Serial.println("Motion ended!");
          pirState = LOW;
      }
  }

  pirState = motion;
  //map(sensorValue,0,1023,0,180);
  if(pirState == HIGH){
    cnt += 1;
    if(cnt > 100){
       cnt = 0;
       angle = angle==120?60:120;
    }
  }else{
    cnt = 0;
    angle = 90;
  }
  servo.write(angle);
  Serial.println(cnt);
  delay(10);
}

