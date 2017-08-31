int rPin = 9;
int gPin = 10;
int bPin = 11;
int r = 255;
int g = 0;
int b = 0;

int relay = 2;
int cnt = 30;
int limit = 135;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Ultrasonic_sensor;
  
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int duration,cm,val;
  digitalWrite(2,HIGH); // 센서에 Trig 신호 입력
  delayMicroseconds(10); // 10us 정도 유지
  digitalWrite(2,LOW); // Trig 신호 off

  duration = pulseIn(3,HIGH);
  cm = microsecondsToCentimeters(duration);

  if (cm > limit){
    cnt = limit+10;
  }

  if (cnt != 0)
  {
    cnt--;
  }
  
  val = cnt;

  Serial.println(cm);
  Serial.println("cm");
  Serial.print(val);
  Serial.println("cm2");

  if(val > limit+1){
    r = 255;
    g = 0;
    b = 0;
  }else{
    r = 0;
    g = 255;
    r = 0;
  }
  
  analogWrite(rPin,r);
  analogWrite(gPin,g);
  analogWrite(bPin,b);

  delay(100);
}

int microsecondsToCentimeters(int microseconds){
  return microseconds / 29 / 2;
}
