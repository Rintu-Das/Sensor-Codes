#include <SPI.h>
#include <RFID.h>
#define SS_PIN 10
#define RST_PIN 9
RFID rfid(SS_PIN, RST_PIN);

String rfidCard;

void setup() {
  Serial.begin(9600);
  Serial.println("Starting the RFID Reader...");
  SPI.begin();
  rfid.init();
  pinMode(8, OUTPUT);
}

void loop() {
  if (rfid.isCard()) {
    if (rfid.readCardSerial()) {
      rfidCard = String(rfid.serNum[0]) + " " + String(rfid.serNum[1]) + " " + String(rfid.serNum[2]) + " " + String(rfid.serNum[3]);
      Serial.println(rfidCard);
      if (rfidCard == "105 230 231 110") {
        digitalWrite(8, HIGH);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(8, HIGH);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
        digitalWrite(8, HIGH);
        delay(100);
        digitalWrite(8, LOW);
        delay(100);
      } else {
        digitalWrite(8, HIGH);
        delay(2000);
        digitalWrite(8, LOW);
      }
    }
    rfid.halt();
  }
}
