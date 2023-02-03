#define LED_PIN 2
#define MOTOR_PIN_1 8
#define MOTOR_PIN_2 9
#define MOTOR_PIN_3 10
#define MOTOR_PIN_4 11
#define TEMP_SENSOR_IN 3
#define TEMP_SENSOR_PIN A2
#define temperature_treshold 28
#define light_treshold 300

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(MOTOR_PIN_1, OUTPUT);
  pinMode(MOTOR_PIN_2, OUTPUT);
  pinMode(MOTOR_PIN_3, OUTPUT);
  pinMode(MOTOR_PIN_4, OUTPUT);
  pinMode(TEMP_SENSOR_IN, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int lightSensorValue = analogRead(A0);
  if (lightSensorValue > light_treshold) {
    digitalWrite(LED_PIN, HIGH);
    Serial.println(1);
    Serial.print(" ");
  } else {
    digitalWrite(LED_PIN, LOW);
    Serial.println(0);
    Serial.print(" ");
  }

  Serial.println(lightSensorValue);
  Serial.print(" ");
  digitalWrite(TEMP_SENSOR_IN, HIGH);
  float temperature = (analogRead(TEMP_SENSOR_PIN) * 100 * 0.00488);
  Serial.println(temperature);
  Serial.print(" ");

  if (temperature > temperature_treshold) {
    Serial.println(1);
    Serial.print(" ");
    for(int i = 0; i < 32; i++){
      clockwiseRotate();
    }
  } else {
    Serial.println(0);
    Serial.print(" ");
    delay(200);
  }
}

void clockwiseRotate() {
  step1();
  step2();
  step3();
  step4();
  step5();
  step6();
  step7();
  step8();
}

void step1() {
  digitalWrite(MOTOR_PIN_1, HIGH);
  digitalWrite(MOTOR_PIN_2, LOW);
  digitalWrite(MOTOR_PIN_3, LOW);
  digitalWrite(MOTOR_PIN_4, LOW);
  delay(2);
}

void step2() {
digitalWrite(MOTOR_PIN_1, HIGH);
digitalWrite(MOTOR_PIN_2, HIGH);
digitalWrite(MOTOR_PIN_3, LOW);
digitalWrite(MOTOR_PIN_4, LOW);
delay(2);
}

void step3() {
digitalWrite(MOTOR_PIN_1, LOW);
digitalWrite(MOTOR_PIN_2, HIGH);
digitalWrite(MOTOR_PIN_3, LOW);
digitalWrite(MOTOR_PIN_4, LOW);
delay(2);
}

void step4() {
digitalWrite(MOTOR_PIN_1, LOW);
digitalWrite(MOTOR_PIN_2, HIGH);
digitalWrite(MOTOR_PIN_3, HIGH);
digitalWrite(MOTOR_PIN_4, LOW);
delay(2);
}

void step5() {
digitalWrite(MOTOR_PIN_1, LOW);
digitalWrite(MOTOR_PIN_2, LOW);
digitalWrite(MOTOR_PIN_3, HIGH);
digitalWrite(MOTOR_PIN_4, LOW);
delay(2);
}

void step6() {
digitalWrite(MOTOR_PIN_1, LOW);
digitalWrite(MOTOR_PIN_2, LOW);
digitalWrite(MOTOR_PIN_3, HIGH);
digitalWrite(MOTOR_PIN_4, HIGH);
delay(2);
}

void step7() {
digitalWrite(MOTOR_PIN_1, LOW);
digitalWrite(MOTOR_PIN_2, LOW);
digitalWrite(MOTOR_PIN_3, LOW);
digitalWrite(MOTOR_PIN_4, HIGH);
delay(2);
}

void step8() {
digitalWrite(MOTOR_PIN_1, HIGH);
digitalWrite(MOTOR_PIN_2, LOW);
digitalWrite(MOTOR_PIN_3, LOW);
digitalWrite(MOTOR_PIN_4, HIGH);
delay(2);
}
