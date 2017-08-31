unsigned long previousTime = 0;
boolean isOn = false;
void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned long currentTime = millis();

  if(currentTime > previousTime + 1000){
    if(isOn){
      digitalWrite(13,HIGH);
    }else{
      digitalWrite(13,LOW);
    }
    isOn = !isOn;
    previousTime = currentTime;
  } 

  
  
  int button = digitalRead(3);
  digitalWrite(2,button);
  delay(10);
}
