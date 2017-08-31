
void setup() {
  pinMode(4,OUTPUT);
  pinMode(3,INPUT);
}

void loop() {
//  int button = digitalRead(3);
  digitalWrite(4,HIGH);
  delay(1000);
//  Serial.print(button);
  digitalWrite(4,LOW);
  delay(1000);
  
}
