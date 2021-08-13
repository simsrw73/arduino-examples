#include <Arduino.h>
#include <Wire.h>

const uint8_t ADDR_TOF10120 = 0x52;

unsigned int TOF10120_ReadDistance();

void setup()
{
  Wire.begin();
  Serial.begin(9600);
}

void loop()
{
  Serial.println(TOF10120_ReadDistance());
  delay(500);
}

unsigned int TOF10120_ReadDistance()
{
  unsigned int distance = 0;

  Wire.beginTransmission(ADDR_TOF10120);
  Wire.write(byte(0)); // sets distance data address (addr)
  Wire.endTransmission();

  // Wait for readings to happen: datasheet suggests at least 30uS
  delay(1);

  Wire.requestFrom(ADDR_TOF10120, 2);

  if (Wire.available())
  {
    unsigned char highByte = 0;
    unsigned char lowByte = 0;
    highByte = Wire.read();
    lowByte = Wire.read();

    distance = (highByte << 8) | lowByte;
  }

  return distance;
}
