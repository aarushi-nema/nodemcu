#include<ESP8266WiFi.h>

const char* ssid= "NodeMCU_network";
const char* password ="RadheRadhe";
 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println();
  Serial.print("Setting soft-AP...");
  WiFi.softAP(ssid, password);
  Serial.print("Access Point: ");
  Serial.print(ssid);
  Serial.println("Started...");
}

void loop() {
  // put your main code here, to run repeatedly:
  int dev= WiFi.softAPgetStationNum();
  Serial.printf("Devices connected= %d\n", dev);
  delay(3000);
}
