#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
const char* ssid     = "SHIFTBRAIN";
const char* password = "r9YBbWZ8GmF";
ESP8266WebServer server(80); // HTTP server on port 80
void setup() {
  Serial.begin(115200);    
  WiFi.disconnect(); // Disconnect AP
  WiFi.mode(WIFI_STA);  
  WiFi.begin(ssid, password); // Connect to WIFI network
  
  while (WiFi.status() != WL_CONNECTED) { // Wait for connection
    delay(500);
    Serial.println(".");
  }
  
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
   
  server.on("/", [](){
    server.send(200, "text/plain", "Hello World");
  });
  
  server.begin(); // Start HTTP server
  Serial.println("HTTP server started.");
}
  
void loop() {
 server.handleClient();
}
