#include "thingProperties.h"
#include <Arduino.h>
#include <math.h> 

const int numSensoren = 5;
const int sensorPins[numSensoren] = {A0, A1, A2, A3, A6}; 

void setup() {
  Serial.begin(9600);
  delay(1500); 
  analogReadResolution(12); 
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();

  for (int i = 0; i < numSensoren; i++) {
    int sensorWert = analogRead(sensorPins[i]);

    float spannung = (sensorWert / 4095.0) * 3.3;

    float feuchte = (spannung * 50) / 3;
    int feuchteGerundet = floor(feuchte); 

    switch (i) {
      case 0: feuchteSensor20cm = feuchte; break;
      case 1: feuchteSensor40cm = feuchte; break;
      case 2: feuchteSensor60cm = feuchte; break;
      case 3: feuchteSensor80cm = feuchte; break;
      case 4: feuchteSensor100cm = feuchte; break;
    }

    Serial.print("Sensor ");
    Serial.print(i + 1);
    Serial.print(" | ");
  
    Serial.print("Spannung: ");
    Serial.print(spannung, 2);
    Serial.print(" V | ");

    Serial.print("Feuchte: ");
    Serial.print(feuchteGerundet);
    Serial.println(" %");
  }

  delay(2000);
}