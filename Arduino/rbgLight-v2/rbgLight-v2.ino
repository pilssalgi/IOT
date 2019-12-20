
int framingoPin = 8;
int rPin = 9;
int gPin = 10;
int bPin = 11;
int IR_sensor = A0;


int r = 255;
int g = 0;
int b = 0;

int cnt = 0;
int limitDistance = 50;
int distanceDelay = 0;

void setup() {
  Serial.begin(9600);
  
  pinMode(2,OUTPUT);
  pinMode(3,INPUT);
  pinMode (IR_sensor, INPUT);
  pinMode (13, OUTPUT);
}

void loop() {
  long IR_value = analogRead(IR_sensor);
  long IR_range = gp2y0a21yk(IR_value);

  
  //  r = IR_range * 2;
  //  g = IR_range / 100 * 255;
  //  b = IR_range / 100 * 255 * 0.5;
  int f_v = 255;

  if(IR_range < limitDistance){
    cnt = IR_range>100?100:IR_range;
  }

  if (cnt > 0){
    cnt*=0.8;
  }

  if(cnt <= 0){
    f_v = 0;
  }else{
    f_v = 255;
  }
  
  Serial.println(IR_range);
  
  analogWrite(rPin,r);
  analogWrite(gPin,g);
  analogWrite(bPin,b);
  analogWrite(framingoPin,f_v);
  analogWrite(13,f_v);
  
  delay(100);
}

long gp2y0a21yk (long IR_value)
{
  if (IR_value < 10) IR_value = 10;
  
  return ((67870.0 / (IR_value - 3.0)) - 40.0)/10;
} 

