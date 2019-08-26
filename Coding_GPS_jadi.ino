#include "UbidotsMicroESP8266.h"

#define TOKEN  "BBFF-5cOFrUyNHxyMK7ZvqKaESrzQmAFu42"  // Put here your Ubidots TOKEN
#define ID_1 "5d5f51381d847277b7b9e9d0" // Latitude
#define ID_2 "5d5f513d1d847277b7b9e9d2" // Longitude
#define ID_3 "5d5f629f1d84720cb5d84ab3" // lokasi
#define WIFISSID "MERTANI" // Put here your Wi-Fi SSID
#define PASSWORD "sdylap2019" // Put here your Wi-Fi password
Ubidots client(TOKEN);
char myGlobalArray[10];
ReadDeviceStatus();

//byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
//char* response = (char *) malloc(sizeof(char) * 400);

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
SoftwareSerial serial_gps(4,5); 
TinyGPSPlus gps;
static const uint32_t GPSBaud = 9600;
double latitude, longitude;
 
void setup() {
  Serial.begin(9600);
  serial_gps.begin(9600);
  Serial.println("GPS Mulai");
  client.wifiConnection(WIFISSID, PASSWORD);
}
 
void loop() {
  
  while(serial_gps.available() > 0) {
    gps.encode(serial_gps.read());
  }
  if(gps.location.isUpdated()) {
    Serial.print("Latitude= ");
    Serial.print(latitude = gps.location.lat(), 6);
    Serial.print("   Longitude= ");
    Serial.println(longitude = gps.location.lng(), 6);
    delay(1000);
    client.add(ID_1, latitude);
    client.add(ID_2, longitude);
    
 
    sendAll(true);

    
    
    
    client.sendAll(false);
    
  
    delay(5000);
  }
  
}
