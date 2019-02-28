//#include <HTTPClient.h>

#include <b64.h>
#include <HttpClient.h>

#include <SoftwareSerial.h>
#include <ESP8266.h>
#include <ESP8266Client.h>

#include <WiFiClient.h>


WiFiClient client;
//HTTPClient http;

#define SSID "SHIFTBRAIN"
#define PASS "r9YBbWZ8GmF"
#define AppID "310ba737157e1b73750825fda41dde70" // openweathermap.org
char server[] = "api.openweathermap.org";
char getPath[] = "data/2.5/weather?id=1850147&APPID=310ba737157e1b73750825fda41dde70";

//1. api.openweathermap.org 
//2. api.openweathermap.org/data/2.5
//3. api.openweathermap.org/data/2.5/weather?
//4. api.openweathermap.org/data/2.5/weather?id=cityID&AppID=
//   Tokyo = 1850147
//   http://api.openweathermap.org/data/2.5/weather?id=1850147&APPID=310ba737157e1b73750825fda41dde70


SoftwareSerial esp8266Serial = SoftwareSerial(2, 3); //rx tx
ESP8266 wifi = ESP8266(esp8266Serial);

void setup()
{
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

    // restart
    Serial.print("restart: ");
    Serial.println(getStatus(wifi.restart()));

    // getVersion
    char version[16] = {};
    Serial.print("getVersion: ");
    Serial.print(getStatus(wifi.getVersion(version, 16)));
    Serial.print(" : ");
    Serial.println(version);

    // getAP
    char ap[32] = {};
    Serial.print("getAP: ");
    Serial.print(getStatus(wifi.getAP(ap)));
    Serial.print(" : ");
    Serial.println(ap);



    /****************************************/
    /******        WiFi commands       ******/
    /****************************************/
    // joinAP
    Serial.print("joinAP: ");
    Serial.println(getStatus(wifi.joinAP(SSID, PASS)));


    /****************************************/
    /******       GET Weather Data ******/
    //client.print(String("GET ") + url + " HTTP/1.1\r\n" + "Host: " + host + "\r\n" +  "Connection: close\r\n\r\n");

    Serial.print("connect: ");
    Serial.println(getStatus(wifi.connect(ESP8266_PROTOCOL_TCP, server, 80)));
    if(wifi.connect(ESP8266_PROTOCOL_TCP,server, 80)) {
      Serial.println("connected to server"); 
      wifi.send("GET http://api.openweathermap.org/data/2.5/weather?id=1850147&APPID=310ba737157e1b73750825fda41dde70 HTTP/1.0\r\n\r\n");
    }
}

void loop()
{
    /****************************************/
    /******        WiFi commands       ******/
    /****************************************/

    // read data
    unsigned int id;
    int length;
    int totalRead;
    char buffer[400] = {};

    if ((length = wifi.available()) > 0) {
      id = wifi.getId();
      totalRead = wifi.read(buffer, 300);
      if (length > 0) {
        Serial.print("Received ");
        Serial.print(totalRead);
        Serial.print("/");
        Serial.print(length);
        Serial.print(" bytes from client ");
        Serial.print("from client ");
        Serial.print(id);
        Serial.print(": ");
        Serial.println((char*)buffer);
        Serial.println(wifi.read());
      }
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
