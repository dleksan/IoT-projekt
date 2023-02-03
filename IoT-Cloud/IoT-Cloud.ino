#include "thingProperties.h"

void setup() {
  Serial.begin(9600);
  delay(1500);

  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  
  if (Serial.available() > 0) {
    onLedStatusChange();
    onLightValueChange();
    onTemperatureChange();
    onMotorStatusChange();
  }
}

void onLightValueChange()  {
  lightValue = Serial.parseFloat();
}

void onTemperatureChange()  {
  temperature = Serial.parseFloat();
}
void onLedStatusChange()  {
  ledStatus = Serial.parseFloat();
}

void onMotorStatusChange()  {
  motorStatus = Serial.parseFloat();
}
