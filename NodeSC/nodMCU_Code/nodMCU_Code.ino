//
// Copyright 2015 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// FirebaseDemo_ESP8266 is a sample that demo the different functions
// of the FirebaseArduino API.

#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define LED 2

// Set these to run example.
#define FIREBASE_HOST "scorpionmfs-jeewaka.firebaseio.com"
#define FIREBASE_AUTH "9Dvti5dwM2XezrrQOEsB238FEWb3XMOBfSCm34wk"
#define WIFI_SSID "Jefferdo IoT"
#define WIFI_PASSWORD "swdKD2h8q56pzD9JktAe5J4x9eAENyUUsQxmz8p9qyGZgHtE5kXjZMC5HnLyxsu"

#define nodeNO "001"
#define nodeName "NIBM"

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, 0);

  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  // set string value
  digitalWrite(LED, HIGH);
  Firebase.setString(nodeNO "/nodeName", nodeName);
  // handle error
  if (Firebase.failed())
  {
    Serial.print("setting /message failed:");
    Serial.println(Firebase.error());
    return;
  }
  digitalWrite(LED, LOW);
}

int n = 0;

void loop()
{
  // set value
  Firebase.setFloat(nodeNO "/temp", random(0, 60));
  // handle error
  if (Firebase.failed())
  {
    Serial.print("setting /number failed:");
    Serial.println(Firebase.error());
    return;
  }
  digitalWrite(LED, HIGH);
  delay(700);
  digitalWrite(LED, LOW);
  delay(300);

  // update value
  Firebase.setFloat(nodeNO "/humid", random(0, 90));
  // handle error
  if (Firebase.failed())
  {
    Serial.print("setting /number failed:");
    Serial.println(Firebase.error());
    return;
  }
  digitalWrite(LED, HIGH);
  delay(700);
  digitalWrite(LED, LOW);
  delay(300);
}
