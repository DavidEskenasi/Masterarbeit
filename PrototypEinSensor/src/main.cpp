#include <Arduino.h>

const int sensorPin = A0;
int sensorValue = 0;

float minValue = 1;  
float maxValue = 1;     

void setup() {
  Serial.begin(9600);
  while (!Serial); 
  analogReadResolution(12); 
}

void loop() {
  sensorValue = analogRead(sensorPin);
  float spannung = (sensorValue / 4095.0) * 3.3;

  if (spannung < minValue) {
    minValue = spannung;
  }

  if (spannung > maxValue) {
    maxValue = spannung;
  }

  Serial.print("Spannung: ");
  Serial.print(spannung);
  Serial.print(" | Maximaler Spannungswert: ");
  Serial.print(maxValue);
  Serial.print(" | Minimaler Spannungswert: ");
  Serial.println(minValue);

  delay(1000);
}