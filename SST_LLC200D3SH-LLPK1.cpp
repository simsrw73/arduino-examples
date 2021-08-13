#include <Arduino.h>

const uint8_t PIN_SST_LIQUID_LEVEL_SWITCH = D5;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_SST_LIQUID_LEVEL_SWITCH, INPUT);
}

void loop() {
  int isDry = digitalRead(PIN_SST_LIQUID_LEVEL_SWITCH);
  if ( isDry ) {
    Serial.println("Dry");
  } else {
    Serial.println("Wet");
  }

  delay(500);
}
