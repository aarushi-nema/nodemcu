#include<ESP8266WiFi.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println();
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
  Serial.println("WiFi network scan started...");

}

void loop() {
  // put your main code here, to run repeatedly:
  int n= WiFi.scanNetworks();
  Serial.println("Scan Complete.");
  if (n==0){
    Serial.println("No Networks Found");
  } else {
    Serial.print(n);
    Serial.println(" Networks Found"); 
    for(int i=0; i<n; i++){
      Serial.print(i+1);
      Serial.print(": ");
      Serial.print(WiFi.SSID(i));
      Serial.print("(");
      Serial.print(WiFi.RSSI(i));
      Serial.print(") MAC: ");
      Serial.print(WiFi.BSSIDstr(i));
      Serial.println((WiFi.encryptionType(i) == ENC_TYPE_NONE)?"UnSecured": "Secured");
      delay(10);
      }
  }
  Serial.println("");
  delay(5000);
}
