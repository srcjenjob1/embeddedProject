#include <Wire.h>

const int ledPin = 13; // onboard LED

void setup() {
  Wire.begin(0x8);
  Wire.onReceive(receiveEvent);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW);
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }
}

void loop() {
  delay(100);
}

void receiveEvent(int howMany) {
  while (Wire.available()) {
    char c = Wire.read();
    Serial.print(c);
    Wire.write('a');
  }
}
