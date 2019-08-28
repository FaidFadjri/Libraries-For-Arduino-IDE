#include "UbidotsMicroESP8266.h"

#define DEVICE  "lampu"  // Put here your Ubidots device label
#define VARIABLE  "led"  // Put here your Ubidots variable label
#define TOKEN  "BBFF-5cOFrUyNHxyMK7ZvqKaESrzQmAFu42"  // Put here your Ubidots TOKEN
#define WIFISSID "KMTEK" // Put here your Wi-Fi SSID
#define PASSWORD "986pswdr" // Put here your Wi-Fi password
#define lampu 12

Ubidots client(TOKEN);

void setup() {
    Serial.begin(115200);
    client.wifiConnection(WIFISSID, PASSWORD);
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN, 1);
    pinMode(lampu, OUTPUT);
    //client.setDebug(true); // Uncomment this line to set DEBUG on
}

void loop() {
    float value = client.getValueWithDevice(DEVICE, VARIABLE);
    if(value == 1){
      digitalWrite(lampu, HIGH);
    }else{
      digitalWrite(lampu,LOW);
    }
    delay(1000);
}
