

float temperature;
void setup() {                

   pinMode(2,OUTPUT);
   pinMode(3,OUTPUT);
  Serial.begin(9600);
  pinMode(8, OUTPUT); 
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
}
void loop() {
  //Upravljanje svjetlosti
  int sensorValueLight = analogRead(A0);

  if(sensorValueLight>400)
  {
    digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);

  }

  Serial.print("Očitavanje fotootprnika:");
  Serial.println(sensorValueLight);
  



  //Upravljanje temperaturom
  digitalWrite(3,HIGH);
  float sensorValue = analogRead(A2);
 
  temperature=(sensorValue)*100*0.00488;

  Serial.print("Temperatura:");
  Serial.println(temperature);

  if(temperature>28)
  {
      for(int i=0;i<32;i++)
      clockwiserotate();
  }

  else
  {
    delay(200);
  }
  
             
}


//Dodatne funkcije za pokretanje motora

void clockwiserotate() { 
  step1();
  step2();
  step3();
  step4();
  step5();
  step6();
  step7();
  step8();
}

void step1(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(2);
  
}
void step2(){
  digitalWrite(8, HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(2);
  
}
void step3(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  delay(2);
}
void step4(){
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(2);
}
void step5(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  delay(2);
}
void step6(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  delay(2);
}
void step7(){
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(2);
}
void step8(){
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
  delay(2); 
}