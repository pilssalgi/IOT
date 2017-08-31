#include "SPI.h"
#include "WiFi.h"

char ssid[] = "SHIFTBRAIN";       //와이파이 SSID
char pass[] = "r9YBbWZ8GmF";   //와이파이 password 

//인스턴스 변수 초기화
WiFiServer server(80);
WiFiClient client;

IPAddress hostIp;
uint8_t ret;

int temp = 0;

String weather_str="";
String wt_temp="";
String wt_wfKor="";
String wt_wfEn="";
String wt_reh="";

void setup() {
  //각 변수에 정해진 공간 할당
  Serial.begin(9600);    
  
  delay(10);
  //WiFi연결 시도
  Serial.println("Connecting to WiFi....");  
  WiFi.begin(ssid, pass);  //WiFi가 패스워드를 사용한다면 매개변수에 password도 작성
  
  server.begin();
  Serial.println("Connect success!");
  Serial.println("Waiting for DHCP address");
  //DHCP주소를 기다린다
//  while(WiFi.localIP() == INADDR_NONE) {
//    Serial.print(".");
//    delay(300);
//  }
  
  Serial.println("\n");
}

void loop() {
}





