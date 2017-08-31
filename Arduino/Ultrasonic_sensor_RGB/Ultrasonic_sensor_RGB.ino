int rPin = 9;
int gPin = 10;
int bPin = 11;

int r = 0;
int g = 0;
int b = 0;
int value = 0;


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
  value+= (cm-value)*0.2;
  
  if(cm < 100){
    r = 255;
    g = 0;
    b = 0;
  }else if(cm < 200){
    r = 0;
    g = 255;
    b = 0;
  }else{
    r = 0;
    g = 0;
    b = 255;
  }
  
  analogWrite(rPin,r);
  analogWrite(gPin,g);
  analogWrite(bPin,b);

  Serial.print(cm);
  Serial.println("cm");
  Serial.println();
  Serial.println(value);

  delay(30);
}

int microsecondsToCentimeters(int microseconds){
  return microseconds / 29 / 2;
}

