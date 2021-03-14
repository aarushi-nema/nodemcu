#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid= "Hare krishna(2.4ghz)";
const char* password= "7977582925";

ESP8266WebServer server(80);
const char htmlPage[] PROGMEM = R"=====(
<HTML> <HEAD> <TITLE>My first web page</TITLE> </HEAD>
<BODY> <CENTER> <B>Hello World.... </B> </CENTER> <marquee
behavior="alternate">NodeMCU ESP8266 Communication Methods and
Protocols</marquee> </BODY> </HTML> )=====";

void handleRoot(){
  digitalWrite(2,0);
  server.send(200, "text/html", htmlPage);
  digitalWrite(2,1);
}

  
void setup() {
  // put your setup code here, to run once:
 Serial.begin(115200);
 delay(10);
 pinMode(2, OUTPUT);
 Serial.println();
 Serial.print("Connecting");
 WiFi.begin(ssid, password);
 while(WiFi.status() != WL_CONNECTED){
  delay(500);
  Serial.print(".");
 }
 Serial.println("");
 Serial.println("WiFi connected");
 Serial.print("IP Address: ");
 Serial.println(WiFi.localIP());

 server.on("/", handleRoot);
 server.begin();
 Serial.println("HTTP server started");
 
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
