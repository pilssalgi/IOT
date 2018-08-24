
const int pwmPin =  6; 
void setup() {
  // put your setup code here, to run once:

  pinMode(pwmPin, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i<180; i++){
    int val = (int)map((int)((sin(DEG_TO_RAD * i) * 1000.0f)), 0, 1000,0,255); 

    Serial.println(val);
    analogWrite(pwmPin, val);
    delay(5);
    
  }

}
