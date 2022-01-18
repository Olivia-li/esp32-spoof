#include <WiFi.h>
#include <esp_wifi.h>

// Set your new MAC Address
uint8_t newMACAddress[] = {0x3c, 0x06, 0x30, 0x1c, 0x50, 0xeb};
const char* ssid     = "BEI_SF";
const char* password = NULL;

const char* soft_ap_ssid = "Olivia-ESP32";
const char* soft_ap_password = "Chipmunk";

WiFiServer server(80);

// Setting new ip address
IPAddress local_IP(192, 168, 1, 184);
// Set your Gateway IP address
IPAddress gateway(192, 168, 1, 1);
IPAddress subnet(255, 255, 255, 0);

void setup(){
  Serial.begin(115200);
  Serial.println();
  
  // Setting the new MAC Address
  Serial.print("[OLD] ESP32 Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
  esp_wifi_set_mac(WIFI_IF_STA, &newMACAddress[0]);
  
  Serial.print("[NEW] ESP32 Board MAC Address:  ");
  Serial.println(WiFi.macAddress());

  if (!WiFi.config(local_IP, gateway, subnet)) {
    Serial.println("STA Failed to configure");
  }
  
  WiFi.mode(WIFI_MODE_APSTA);
  WiFi.softAP(soft_ap_ssid, soft_ap_password);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.print("ESP32 IP as soft AP: ");
  Serial.println(WiFi.softAPIP());

  Serial.print("ESP32 IP on the WiFi network: ");
  Serial.println(WiFi.localIP());

  server.begin();
}
 
void loop(){

}
