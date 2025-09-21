#include <Arduino.h>
#include <math.h> 

const int numSensoren = 5;
const int sensorPins[numSensoren] = {A0, A1, A2, A3, A6};

void setup() {
  Serial.begin(9600);
  while (!Serial); 
  analogReadResolution(12); 
}

void loop() {
  for (int i = 0; i < numSensoren; i++) {
    int sensorWert = analogRead(sensorPins[i]);

    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(" | ");

    float spannung = (sensorWert / 4095.0) * 3.3;
    Serial.print("Spannung: ");
    Serial.print(spannung, 2);
    Serial.print(" V | ");

    float feuchte = (spannung * 50) / 3;

    int feuchteGerundet = floor(feuchte); 
    Serial.print("Feuchte: ");
    Serial.print(feuchteGerundet);
    Serial.println(" %");
  }

  Serial.println("----------------------------");
  delay(2000); 
}