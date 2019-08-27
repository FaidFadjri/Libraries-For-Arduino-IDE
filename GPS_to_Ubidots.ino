#include "UbidotsMicroESP8266.h"

#include <TinyGPS++.h>
#include <SoftwareSerial.h>
SoftwareSerial serial_gps(0,4); 
TinyGPSPlus gps;
static const uint32_t GPSBaud = 9600;
double latitude, longitude;

#define TOKEN  "BBFF-5cOFrUyNHxyMK7ZvqKaESrzQmAFu42"  // Put here your Ubidots TOKEN
#define ID_1 "5d5f51381d847277b7b9e9d0" // Latitude
#define ID_2 "5d5f513d1d847277b7b9e9d2" // Longitude
#define WIFISSID "MERTANI" // Put here your Wi-Fi SSID
#define PASSWORD "sdylap2019" // Put here your Wi-Fi password

Ubidots client(TOKEN);

void setup(){
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
    serial_gps.begin(9600);
    Serial.println("GPS Mulai");
    //client.setDebug(true); // Uncomment this line to set DEBUG on
}

void loop(){
   while(serial_gps.available() > 0) {
    gps.encode(serial_gps.read());
  }
  if(gps.location.isUpdated()) {
    Serial.print("Latitude =");
    Serial.print(latitude = gps.location.lat(),6);
    Serial.print(" & Longitude = ");
    Serial.println(longitude = gps.location.lng(),6);
    delay(1000);
    client.add(ID_1, latitude);
    client.add(ID_2, longitude);
    client.sendAll(false);
    delay(5000);
  }
   
    //float value2 = analogRead(2)
    
}
