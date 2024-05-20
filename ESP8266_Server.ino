#include <ESP8266WiFi.h>

int port = 14552
WiFiServer server(port);

IPAddress staip(192,168,1,8);
IPAddress stagateway(192,168,1,1);
IPAddress stamsk(255,255,255,0);

const char* SSID = "CMCC-";
const char* PASSWD = "5f2m2ey3";

int packetSize;

void setup() {
  //	Init
  pinMode(0, OUTPUT);
  pinMode(2, OUTPUT);
  //digitalWrite(2, LOW);
  Serial.begin(115200);
  Serial.println();

  WiFiInit_STA();

  //	Finish
  digitalWrite(2, HIGH);
}

void loop() {
  WiFiClient client = server.available();
  while(client.connected()){
    while(client.available()>0){
      String msg = client.read();
    }

    //handle msg()

    client.println("msg");
    
  }
}



void WiFiInit_STA(){
  WiFi.mode(WIFI_STA);
  WiFi.config(staip, stagateway, stamsk);
  WiFi.begin(SSID, PASSWD);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print('.');
    delay(500);
  }
  Serial.println();
  Serial.println("Mode: STA");
  Serial.print("IP address: ");
  Serial.print(WiFi.localIP());
  Serial.print(" on port ");
  Serial.println(port);
}

/*
  packetSize = Udp.parsePacket();
  if (packetSize) {
    byte InPacket[packetSize];
    Udp.read(InPacket, packetSize);
    switch(InPacket[0]){
      case 0b00000000:
        digitalWrite(2, HIGH);
        digitalWrite(0, LOW);
        Serial.println("ON");
        break;
      case 0b00000001:
        digitalWrite(2, LOW);
        digitalWrite(0, HIGH);
        Serial.println("OFF");
        break;
    }
  }
*/
