void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  //HIGH,LOW
  int button = digitalRead(3);
  digitalWrite(2,button);
  delay(10);
}


