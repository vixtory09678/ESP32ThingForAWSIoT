#include <Arduino.h>
#include <ESP_LM35.h>
#include <ArduinoJson.h>
#include "network_config.h"

ESP_LM35 lm35(39);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  // verify certificate in file system
  if (!verifyCertificate()) return;
  
  // connect to wifi
  WiFi.begin(SSID, PASS);
  while(WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  } Serial.println("\nWiFi connected");

  // set certificate to client object
  clientSecure.setCACert(ca_str.c_str());
  clientSecure.setCertificate(cert_str.c_str());
  clientSecure.setPrivateKey(pri_key_str.c_str());

  // set client object to mqtt object
  mqtt.setClient(clientSecure);
  mqtt.setServer(AWS_HOST, MQTT_PORT);

  if (mqtt.connect(CLIENT_ID)) {
    Serial.println("MQTT Connected");
  }
}

void loop() {
  // prepare json data
  StaticJsonDocument<256> doc;
  double run_time = millis() / 1000.0;
  doc["temp"] = lm35.tempC();
  doc["run_time"] = run_time;
  
  // transform json object to json string
  String msg;
  serializeJson(doc, msg);

  // publish data to AWS IoT Service
  mqtt.publish("data/temp", msg.c_str());

  delay(5000);
}