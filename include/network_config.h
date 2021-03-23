#ifndef NETWORK_CONFIG_H
#define NETWORK_CONFIG_H

#include <SPIFFS.h>
#include <FS.h>
#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <PubSubClient.h>

#define SSID "Your SSID"
#define PASS "Your PASSWORD"

WiFiClientSecure clientSecure;

#define AWS_HOST "YOUR AWS HOST"
#define MQTT_PORT 8883
#define CLIENT_ID "esp32-clientID"

PubSubClient mqtt;
String ca_str, cert_str, pri_key_str;

bool verifyCertificate () {
  bool isFileSystemReady = SPIFFS.begin();
  bool isCAExist = SPIFFS.exists("/CA.pem");
  bool isCertExist = SPIFFS.exists("/certificate.crt");
  bool isPrivateKeyExist  =SPIFFS.exists("/private_key.key");

  // check file system
  if (!isFileSystemReady) {
    Serial.println(F("SPIFFS is not ready."));
    return false;
  }

  // check certificate file
  if (!isCAExist || !isCertExist || !isPrivateKeyExist) {
    Serial.println(F("File is not exist"));
    return false;
  }

  // if all success, read file to string
  ca_str = SPIFFS.open("/CA.pem").readString();
  cert_str = SPIFFS.open("/certificate.crt").readString();
  pri_key_str = SPIFFS.open("/private_key.key").readString();

  return true;
}



#endif