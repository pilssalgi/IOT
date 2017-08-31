void setup() {
  // put your setup code here, to run once:
   pinMode(3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int sensorValue = analogRead(A0);
  analogWrite(3,sensorValue/4);
  delay(50);
}
