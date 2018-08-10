#include <Servo.h>


int inPin = 7;
int deg = 0; 
int moveDelay = 0;

Servo myservo; 
void setup()

{

  Serial.begin(9600); // open serial, set baud rate to 9600 bps
  pinMode(inPin, INPUT); // 7번 핀을 input 모드로 설정

  myservo.attach(7);

}

void loop()

{

      int val;

      
      val=analogRead(A0);   // 아날로그 핀 번호에 맞게 수정

      Serial.print("mic = ");
      Serial.println(val); //print sound value to Serial        

      if(moveDelay==0){
        if(val > 21){
          deg = 180;
          moveDelay = 30;
          myservo.write(deg);
        }else{
          deg = 0;
          myservo.write(deg);
        }

         
      }

      if(moveDelay>0){
        moveDelay--;
      }

        Serial.print("moveDelay = ");
        Serial.println(moveDelay);
        
        Serial.print("degree = ");
        Serial.println(deg);
        delay(100);
//  
//      for(pos = 0; pos < 180; pos += 1)  // 0도에서 180도로 이동합니다.
//      {                                  // 이동할때 각도는 1도씩 이동합니다. 
//        myservo.write(pos);              // 'pos'변수의 위치로 서보를 이동시킵니다.
//        delay(15);                       // 서보 명령 간에 20ms를 기다립니다.
//      } 
//      for(pos = 180; pos>=1; pos-=1)     // 180도에서 0도로 이동합니다.
//      {                                
//        myservo.write(pos);              // 서보를 반대방향으로 이동합니다.
//        delay(15);                       // 서보 명령 간에 20ms를 기다립니다.
//      } 

      //myservo.write(degredd );

}

