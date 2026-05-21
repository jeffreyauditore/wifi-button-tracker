#include <WiFi.h>
#include <WiFiClient.h>

#define WIFI_SSID    "Wokwi-GUEST"   // в Wokwi завжди такий
#define WIFI_PASS    ""               // пароль порожній
#define TS_API_KEY   "YOUR WRITE KEY"

const char* server = "api.thingspeak.com"; 
WiFiClient client;

const int button_1_Pin = 12;
const int button_2_Pin = 5;
const int button_3_Pin = 2;

int button_1_Counter = 0;
int button_2_Counter = 0;
int button_3_Counter = 0;

int last_1_State = 0;
int last_2_State = 0;
int last_3_State = 0;

void sendToThingSpeak(int f1, int f2, int f3) {
  if (client.connect(server, 80)) {
    String data = "field1=" + String(f1) +
                  "&field2=" + String(f2) +
                  "&field3=" + String(f3);

    client.println("POST /update HTTP/1.1");
    client.println("Host: api.thingspeak.com");
    client.println("Connection: close");
    client.println("X-THINGSPEAKAPIKEY: " + String(TS_API_KEY));
    client.println("Content-Type: application/x-www-form-urlencoded");
    client.println("Content-Length: " + String(data.length()));
    client.println();
    client.println(data);
    delay(200);
    client.stop();
    Serial.println("Відправлено: " + data);
  }
}

void setup() {
  Serial.begin(115200);
  pinMode(button_1_Pin, INPUT_PULLUP);
  pinMode(button_2_Pin, INPUT_PULLUP);
  pinMode(button_3_Pin, INPUT_PULLUP);

  WiFi.begin(WIFI_SSID, WIFI_PASS);
  Serial.print("Підключення");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nПідключено!");
}

void loop() {
  int s1 = digitalRead(button_1_Pin);
  int s2 = digitalRead(button_2_Pin);
  int s3 = digitalRead(button_3_Pin);

  if (s1 != last_1_State && s1 == LOW) {
    button_1_Counter++;
    Serial.println("Good: " + String(button_1_Counter));
    sendToThingSpeak(button_1_Counter, button_2_Counter, button_3_Counter);
  }
  if (s2 != last_2_State && s2 == LOW) {
    button_2_Counter++;
    Serial.println("Medium: " + String(button_2_Counter));
    sendToThingSpeak(button_1_Counter, button_2_Counter, button_3_Counter);
  }
  if (s3 != last_3_State && s3 == LOW) {
    button_3_Counter++;
    Serial.println("Bad: " + String(button_3_Counter));
    sendToThingSpeak(button_1_Counter, button_2_Counter, button_3_Counter);
  }

  last_1_State = s1;
  last_2_State = s2;
  last_3_State = s3;
}