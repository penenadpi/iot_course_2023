// Example testing sketch for various DHT humidity/temperature sensors
// Written by ladyada, public domain

// REQUIRES the following Arduino libraries:
// - DHT Sensor Library: https://github.com/adafruit/DHT-sensor-library
// - Adafruit Unified Sensor Lib: https://github.com/adafruit/Adafruit_Sensor

#include "DHT.h"

#define DHTPIN 10     // Digital pin connected to the DHT sensor

#define DHTTYPE DHT11   // DHT 22  (AM2302), AM2321

DHT dht(DHTPIN, DHTTYPE);
char command;
float t;
float v;

void setup() {
  Serial.begin(9600);
  Serial.println("DHT11 test!");
  dht.begin();
}

void loop() {

  if(Serial.available()){
    command = Serial.read();
    Serial.println(command);
    if(command=='t'){
      t = dht.readTemperature();
      if(isnan(t))
      Serial.println("Greska prilikom citanja temperature!");
      else{
        Serial.println("Temperatura:");
        Serial.print(t);
        Serial.print("°C "); 
        delay(1000);
     }
    }
    if(command=='v'){
      v = dht.readHumidity();
      if(isnan(v))
      Serial.println("Greska prilikom citanja vlaznosti!");
      else{ 
        Serial.println("Vlaznost:");
        Serial.print(v);
        Serial.print("%"); 
        delay(1000);
     }
    }
 
  }

}
