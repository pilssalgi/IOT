void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
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

  delay(30);
}

int microsecondsToCentimeters(int microseconds){
  return microseconds / 29 / 2;
}

