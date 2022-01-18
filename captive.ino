#include <WiFi.h>

// AP network settings
const char* soft_ap_ssid = "Olivia-ESP32";
const char* soft_ap_password = "Chipmunk";

// STA network settings
const char* ssid     = "BEI_SF";
const char* password = NULL;

// MAC address variables
uint8_t newMACAddress[] = {0x3c, 0x06, 0x30, 0x1c, 0x50, 0xeb};

// Setting new ip address
IPAddress local_IP(172, 20, 7, 121);
// Set your Gateway IP address
IPAddress gateway(172, 20, 0, 1);
IPAddress subnet(255, 255, 240, 0);

// Set web server port number to 80
WiFiServer server(80);

void setup() {

  Serial.begin(115200);

  Serial.print("[OLD] ESP32 Board MAC Address:  ");
  Serial.println(WiFi.macAddress());
  
//  esp_wifi_set_mac(WIFI_IF_STA, &newMACAddress[0]);
  esp_base_mac_addr_set(newMACAddress);
  Serial.print("[NEW] ESP32 Board MAC Address:  ");
  Serial.println(WiFi.macAddress());

  WiFi.mode(WIFI_AP_STA);
  
  // Setup soft AP 
  Serial.print("Setting AP (Access Point)…");
  WiFi.softAP(soft_ap_ssid, soft_ap_password);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.println("Connecting to WiFi..");
  }

  Serial.print("ESP32 IP as soft AP: ");
  Serial.println(WiFi.softAPIP());

  Serial.print("ESP32 IP on the WiFi network: ");
  Serial.println(WiFi.localIP());
  
}

void loop(){
 
}
