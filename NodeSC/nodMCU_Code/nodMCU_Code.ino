#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define LED 2

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
