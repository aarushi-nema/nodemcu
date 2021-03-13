#include<ESP8266WiFi.h>

const char* ssid= "Hare krishna(2.4ghz)";
const char* password= "7977582925";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println();
  Serial.println("Setting WiFi mode...");
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  Serial.println("Connecting to ");
  Serial.print(ssid);
  while(WiFi.status()!= WL_CONNECTED){
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected, IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.printf("Signal Strength in dB= %d\n", WiFi.RSSI());
  delay(3000);

}
