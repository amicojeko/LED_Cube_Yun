
#include <Bridge.h>
#include <HttpClient.h>
#include <SoftwareSerial.h>
SoftwareSerial mySerial(10, 11); // RX, TX
void setup() {
  pinMode(13, OUTPUT);
  digitalWrite(13, LOW);
  Bridge.begin();
  mySerial.begin(2400);
}

void loop() {
  HttpClient client;
  client.get("http://aws.jeko.net/1.html");
  
  while (client.available()) {
    char c = client.read();
    mySerial.print(c);
  }
  mySerial.flush();
  
  delay(5000);
}
