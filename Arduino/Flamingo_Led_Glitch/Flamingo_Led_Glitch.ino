
const int ledPin =  6; 
const int buttonPin = 2;     // the number of the pushbutton pin

int buttonState = 0;
int ledPower = 0;
int glitch = 0;
int glitchCount = 0;
int randomNumber = 0;
bool isGlitch = false;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH) {
    // turn LED on:

   ledPower = 255;
   
   if(random(1) < 0.1 && !isGlitch){
      delay(1000);
      isGlitch = true;
      glitchCount = random(100);
      Serial.println("glitch start");
   }

   if(isGlitch){
      glitchCount++;
      glitchCount+=random(10);
      if(glitchCount>= 255){
        glitchCount = 255;
        isGlitch = false;
      }
      glitch = random(255-glitchCount);
      if(glitch < 0)glitch = 0;
      ledPower -= glitch;
   }
      

//    if(glitchCount >= 256){
//      glitchCount = 256;
//    }
//    
    
//    glitch = random(256);
    
    analogWrite(ledPin, ledPower);  // analogWrite values from 0 to 255
    Serial.println("buttonState : " + String(ledPower));
  } else {
    // turn LED off:
    glitchCount = 0;
    ledPower = 0;
    analogWrite(ledPin, ledPower);
    Serial.println("buttonState : LOW");
  }

  delay(100);
}
