#include <SoftwareSerial.h>
#include <ESP8266.h>

SoftwareSerial esp8266Serial = SoftwareSerial(10, 11);
ESP8266 wifi = ESP8266(esp8266Serial);

#define SSID "SHIFTBRAIN"
#define PASS "r9YBbWZ8GmF"
#define DST_IP "162.243.53.59"

String location = "Tokyo";
String data = "";
int ended = 0;
unsigned long lastAttemptTime = 0;            // 마지막으로 서버에서 데이터를 전송받은 시간
String currentLine = "";          // 서버에서 전송된 데이터 String저장
String tempString = "";           // 온도 저장 변수
String humString = "";            // 습도 저장 변수
String timeString = "";           // 시간 정보 변수
String pressureString = "";       // 압력 정보 변수
boolean readingTemp = false;      //온도 데이터가 있는지 여부 판단
boolean readingHum = false;       //습도 데이터가 있는지 여부 판단
boolean readingTime = false;      //시간 데이터가 있는지 여부 판단
boolean readingPressure = false;  //압력 데이터가 있는지 여부 판단
int temp = 0;

void setup()
{
    currentLine.reserve(100);
    tempString.reserve(10);
    humString.reserve(10);
    timeString.reserve(20);

    Serial.begin(9600);

    // ESP8266
    esp8266Serial.begin(9600);
    wifi.begin();
    wifi.setTimeout(1000);

    /****************************************/
    /******       Basic commands       ******/
    /****************************************/
    // test
    Serial.print("test: ");
    Serial.println(getStatus(wifi.test()));

//    Serial.println(wifi.);
    
    // restart
    Serial.print("restart: ");
    Serial.println(getStatus(wifi.restart()));

    // getVersion
    char version[16] = {};
    Serial.print("getVersion: ");
    Serial.print(getStatus(wifi.getVersion(version, 16)));
    Serial.print(" : ");
    Serial.println(version);


    /****************************************/
    /******        WiFi commands       ******/
    /****************************************/
    // setWifiMode
//    Serial.print("setWifiMode: ");
//    Serial.println(getStatus(wifi.setMode(ESP8266_WIFI_STATION)));
      wifi.setMode(ESP8266_WIFI_STATION);
    
    // joinAP
    Serial.print("Connect WIFI : ");
    Serial.println(getStatus(wifi.joinAP(SSID, PASS)));

      // getAP
//    char ap[32] = {};
//    Serial.print("getAP: ");
//    Serial.print(getStatus(wifi.getAP(ap)));
//    Serial.println(ap);

   /****************************************/
    /******       TCP/IP commands      ******/
    /****************************************/
    // connect
    Serial.print("connect: ");
    Serial.println(getStatus(wifi.connect(ESP8266_PROTOCOL_TCP, "api.openweathermap.org",80)));
    getConnectionStatue(wifi);
    
    // send
    Serial.print("send: ");
    Serial.println(getStatus(wifi.send("GET /data/2.5/weather?id=1850147&appid=310ba737157e1b73750825fda41dde70 HTTP/1.0\n\n")));
  
    // close
//    Serial.print("close: ");
//    Serial.println(getStatus(wifi.close(wifi.getId())));

}

void loop()
{ 
  
    /****************************************/
    /******        WiFi commands       ******/
    /****************************************/
    // getConnectedStations
//    ESP8266Station stations[5];
//    unsigned int stationCount;
//    Serial.print("getConnectedStations: ");
//    Serial.print(getStatus(wifi.getConnectedStations(stations, stationCount, 5)));
//    Serial.print(" : ");
//    Serial.println(stationCount);
//    for (uint8_t i = 0; i < stationCount; i++) {
//      Serial.print(" - ");
//      Serial.print(stations[i].ip);
//      Serial.print(" - ");
//      for (uint8_t j = 0; j < 6; j++) {
//        Serial.print(stations[i].mac[j], HEX);
//        if (j < 5)
//          Serial.print(":");
//      }
//      Serial.println();
//    }
//    delay(5000);

    /****************************************/
    /******       TCP/IP commands      ******/
    /****************************************/
    // getConnectionStatus
//    ESP8266ConnectionStatus connectionStatus;
//    ESP8266Connection connections[5];
//    unsigned int connectionCount;
//    Serial.print("getConnectionStatus: ");
//    Serial.print(getStatus(wifi.getConnectionStatus(connectionStatus, connections, connectionCount)));
//    Serial.print(" : ");
//    Serial.println(connectionCount);
//    for (int i = 0; i < connectionCount; i++) {
//      Serial.print(" - Connection: ");
//      Serial.print(connections[i].id);
//      Serial.print(" - ");
//      Serial.print(getProtocol(connections[i].protocol));
//      Serial.print(" - ");
//      Serial.print(connections[i].ip);
//      Serial.print(":");
//      Serial.print(connections[i].port);
//      Serial.print(" - ");
//      Serial.println(getRole(connections[i].role));
//    }
//    delay(5000);


    // read data
//    unsigned int id;
//    int length;
//    int totalRead;
//    char buffer[101] = {};
//
//    if ((length = wifi.available()) > 0) {
//      id = wifi.getId();
//      totalRead = wifi.read(buffer, 100);
//      //Serial.println(wifi.read());
//
//      Serial.print("Received :");
//      Serial.println(totalRead);
//      if (totalRead > 0) {
////        Serial.print("Received ");
////        Serial.print("/");
////        Serial.print(length);
////        Serial.print(" bytes from client ");
////        Serial.print(id);
////        Serial.print(": ");
//          Serial.print((char*)buffer);
//          data += (char*)buffer;
////          Serial.print(data);
//      }
//
//      if(totalRead == 0 && ended == 0){
//          ended = 1;
//          Serial.print("data :");
//          Serial.println(data);
//          wifi.close(wifi.getId());
//          data = "";
////        Serial.println(data);
//      }
//    }

}
void getConnectionStatue(ESP8266 wifi) {
  // getConnectionStatus
  ESP8266ConnectionStatus connectionStatus;
  ESP8266Connection connections[5];
  unsigned int connectionCount;
  Serial.print("getConnectionStatus: ");
  Serial.print(getStatus(wifi.getConnectionStatus(connectionStatus, connections, connectionCount)));
  Serial.print(" : ");
  Serial.println(connectionCount);
  for (int i = 0; i < connectionCount; i++) {
    Serial.print(" - Connection: ");
    Serial.print(connections[i].id);
    Serial.print(" - ");
    Serial.print(getProtocol(connections[i].protocol));
    Serial.print(" - ");
    Serial.print(connections[i].ip);
    Serial.print(":");
    Serial.print(connections[i].port);
    Serial.print(" - ");
    Serial.println(getRole(connections[i].role));
  }
}
 
String getStatus(bool status)
{
    if (status)
        return "OK";

    return "KO";
}

String getStatus(ESP8266CommandStatus status)
{
    switch (status) {
    case ESP8266_COMMAND_INVALID:
        return "INVALID";
        break;

    case ESP8266_COMMAND_TIMEOUT:
        return "TIMEOUT";
        break;

    case ESP8266_COMMAND_OK:
        return "OK";
        break;

    case ESP8266_COMMAND_NO_CHANGE:
        return "NO CHANGE";
        break;

    case ESP8266_COMMAND_ERROR:
        return "ERROR";
        break;

    case ESP8266_COMMAND_NO_LINK:
        return "NO LINK";
        break;

    case ESP8266_COMMAND_TOO_LONG:
        return "TOO LONG";
        break;

    case ESP8266_COMMAND_FAIL:
        return "FAIL";
        break;

    default:
        return "UNKNOWN COMMAND STATUS";
        break;
    }
}

String getRole(ESP8266Role role)
{
    switch (role) {
    case ESP8266_ROLE_CLIENT:
        return "CLIENT";
        break;

    case ESP8266_ROLE_SERVER:
        return "SERVER";
        break;

    default:
        return "UNKNOWN ROLE";
        break;
    }
}

String getProtocol(ESP8266Protocol protocol)
{
    switch (protocol) {
    case ESP8266_PROTOCOL_TCP:
        return "TCP";
        break;

    case ESP8266_PROTOCOL_UDP:
        return "UDP";
        break;

    default:
        return "UNKNOWN PROTOCOL";
        break;
    }
}
