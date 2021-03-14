#include <ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  delay(500);
  while(!Serial){ 
    delay(100); 
    }
  Serial.print("ESP8266 MAC: ");
  Serial.print(WiFi.macAddress());

}

void loop() {
  // put your main code here, to run repeatedly:
   //Serial.print(WiFi.macAddress());
   //delay(100000);

}
