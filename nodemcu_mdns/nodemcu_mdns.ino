#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>

const char* ssid= "Hare krishna(2.4ghz)";
const char* password= "7977582925";
ESP8266WebServer server(80);

void handleRoot(){
  digitalWrite(2,0);
  server.send(200, "text/plain", "hello from ESP8266! mDNS demo");
  digitalWrite(2,1);
}
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(10);
  Serial.println();
  Serial.print("Connecting to ");
  Serial.print(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED){
    Serial.print(".");
    delay(500);
  }
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  if (WiFi.status() == WL_CONNECTED){
    if (MDNS.begin("esp8266")){
      Serial.println("MDNS started at esp8266.local");
    }
  }

  server.on("/", handleRoot);
  server.begin();
  Serial.println("HTTP server started");
}

void loop() {
  // put your main code here, to run repeatedly:
  server.handleClient();
}
