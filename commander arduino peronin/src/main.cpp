// source: https://www.youtube.com/watch?v=zFEReI1IZ3A

//*************************** Declaration des includes *******************************
#include <Arduino.h>
#include "infoConnection.h" // contient SSID et PSW
#include "WiFi.h"

IPAddress ip(192, 168, 1, 78);
IPAddress dns(192, 168, 1, 254);
IPAddress gateway(192, 168, 1, 254);
IPAddress subnet(255, 255, 255, 0);
const byte Led = 4;

//void get_network_info();
//void connected_to_ap();
//void got_ip_from_ap();


void connected_to_ap(WiFiEvent_t wifi_event, WiFiEventInfo_t wifi_info){
    Serial.println("\nConnected to the WiFi network");
}

void got_ip_from_ap(WiFiEvent_t wifi_event, WiFiEventInfo_t wifi_info){
    Serial.print("[*] Network information for ");
    Serial.println(ssid);

    Serial.println("[+] BSSID : " + WiFi.BSSIDstr());
    Serial.print("[+] Gateway IP : ");
    Serial.println(WiFi.gatewayIP());
    Serial.print("[+] Subnet Mask : ");
    Serial.println(WiFi.subnetMask());
    Serial.println((String)"[+] RSSI : " + WiFi.RSSI() + " dB");
    Serial.print("[+] ESP32 IP : ");      
    Serial.println(WiFi.localIP());
  
}
void disconnected_from_ap(WiFiEvent_t wifi_event, WiFiEventInfo_t wifi_info)
{
    Serial.println("[-] Disconnected from the WiFi AP");
    WiFi.begin(ssid, password);
}
void setup()
{
    Serial.begin(115200);
    delay(100);

    WiFi.mode(WIFI_STA); //Optional
    WiFi.onEvent(connected_to_ap, SYSTEM_EVENT_STA_CONNECTED);
    WiFi.onEvent(got_ip_from_ap, SYSTEM_EVENT_STA_GOT_IP);
    WiFi.onEvent(disconnected_from_ap, SYSTEM_EVENT_STA_DISCONNECTED);


    WiFi.config(ip, dns, gateway, subnet);
    WiFi.begin(ssid, password);
    Serial.println("\nConnecting");
}

void loop()
{

}
