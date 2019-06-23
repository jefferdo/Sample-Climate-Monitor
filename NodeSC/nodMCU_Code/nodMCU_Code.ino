#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>
#include <DHT.h>

#define LED 2
#define DHTTYPE DHT11
#define DHTPIN D4

#define FIREBASE_HOST "scorpionmfs-jeewaka.firebaseio.com"
#define FIREBASE_AUTH "9Dvti5dwM2XezrrQOEsB238FEWb3XMOBfSCm34wk"

#define WIFI_SSID "Cisco LAB"
#define WIFI_PASSWORD "CISCO@123"

#define nodeNO "001"
#define nodeName "APTS"

DHT dht(DHTPIN, DHTTYPE);

void setup()
{
  pinMode(LED, OUTPUT);
  digitalWrite(LED, 0);
  dht.begin();
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
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  Serial.println(h);
  Serial.println(t);
  // set value
  Firebase.setFloat(nodeNO "/temp", t);
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
  Firebase.setFloat(nodeNO "/humid", h);
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
