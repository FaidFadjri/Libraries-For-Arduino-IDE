#include "UbidotsMicroESP8266.h"

#define TOKEN  "BBFF-5cOFrUyNHxyMK7ZvqKaESrzQmAFu42"  // Put here your Ubidots TOKEN
#define ID_1 "5d5cc3ea1d84721a5f7aea70" // Berat
#define WIFISSID "MERTANI" // Put here your Wi-Fi SSID
#define PASSWORD "sdylap2019" // Put here your Wi-Fi password
int sensorpin =A0;
int sensorValue = 0;

Ubidots client(TOKEN);

void setup(){
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
    
    //client.setDebug(true); // Uncomment this line to set DEBUG on
}

void loop(){
    sensorValue = analogRead(sensorpin);
    int berat = sensorValue;
    client.add(ID_1, berat);
    client.sendAll(false);
    delay(5000);
    
    
}
