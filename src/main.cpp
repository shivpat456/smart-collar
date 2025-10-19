#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  
  WiFi.mode(WIFI_STA);
  WiFi.disconnect();
  delay(100);
}
void loop() {
  Serial.println("finding networks\n");
  
  int n = WiFi.scanNetworks();
  
  if (n == 0) {
    Serial.println("no networks found");
  } else {
    Serial.printf("%dnetworks:\n\n", n);
    
    for (int i = 0; i < n; i++) {
      Serial.printf("%2d: ", i + 1);
      Serial.printf("%-32s ", WiFi.SSID(i).c_str());
      int rssi = WiFi.RSSI(i);
      Serial.printf("(%3d dBm) ", rssi);
    
      Serial.printf(" [Ch:%d]\n", WiFi.channel(i));
    }
  }
  
  delay(5000);
}
