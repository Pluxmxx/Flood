#include <WiFi.h>
#include <TridentTD_LineNotify.h>

#define SSID "Your wifi name"
#define PASSWORD "you wifi password"
#define LINE_TOKEN "you line-token"

int sensor = 34;
int water = 0; 
  
void setup() {
  pinMode(sensor, INPUT);
  
  Serial.begin(9600);
  WiFi.begin(SSID, PASSWORD);
  
  LINE.setToken(LINE_TOKEN);
}

void loop() {
  water = analogRead(sensor);
  Serial.println(water);
  if(water < 500) {
    Serial.println("No Water");
  }
  if(water > 500) {
    Serial.println("water");
    delay(100);
    LINE.notify("Water level is above 10cm");
    delay(10000);
  }
delay(200);
}
