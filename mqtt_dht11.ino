#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
#include "DHT.h"
#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE, 4);

void subscribeReceive(char* topic, char* payload, unsigned int length);

byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192, 168, 1, 212);

const char* server = "broker.hivemq.com";
char message[50];
char velicina[15];

int izmereno;

EthernetClient ethClient;
PubSubClient mqttClient(ethClient);

void setup() {
  strcpy(velicina, "temperatura");
  dht.begin();

  Serial.begin(9600);

  Ethernet.begin(mac, ip);

  delay(3000);

  mqttClient.setServer(server, 1883);

  while (!mqttClient.connect("testklijentID"))
  {
    Serial.println("Cekam konekciju...");
  }
  Serial.println("Konekcija uspešno uspostavljena");

  mqttClient.setCallback(subscribeReceive);
  mqttClient.subscribe("promena_velicine");

}

void loop() {
  mqttClient.loop();

  if (strcmp(velicina, "temperatura") == 0) {
    izmereno = dht.readTemperature();
    if (isnan(izmereno)) {
      izmereno = random(30);
    }
    izmereno = random(40);
    sprintf(message, "Izmerena temperatura: %d°C", izmereno);
    if (mqttClient.publish("merenje-temperatura", message)) {
      Serial.print("Uspesno poslato");
    }
    else Serial.print("Neuspesno slanje\n");
  }
  else if (strcmp(velicina, "vlaznost") == 0) {
    izmereno = dht.readHumidity();
    if (isnan(izmereno)) {
      izmereno = random(30);
    }
    izmereno = random(100);
    sprintf(message, "Izmerena vlaznost: %d%%", izmereno);
    if (mqttClient.publish("merenje-vlaznost", message)) {
        Serial.print("Uspesno poslato\n");
    }
    else Serial.print("Neuspesno slanje");
  }
  delay(4000);
}

void subscribeReceive(char* topic, char* payload, unsigned int length)
{

  Serial.print("Primljeno: ");
  for (int i = 0; i < length; i ++)
  {
    Serial.print(char(payload[i]));

  }
  Serial.println("");

  if (strncmp(payload, "temperatura", length) == 0 || strncmp(payload, "vlaznost", length) == 0 || strncmp(payload, "stop", length) == 0) {
    if (!strncmp(velicina, payload, length) == 0) {
      strncpy(velicina, payload, length);
      velicina[length] = '\0';
      Serial.print("Promenjena velicina");
    }
  }
  else Serial.print("Nepoznata velicina");
  Serial.println("");
}
