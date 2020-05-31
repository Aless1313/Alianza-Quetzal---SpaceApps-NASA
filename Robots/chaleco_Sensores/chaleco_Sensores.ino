#include <Key.h>
#include <Keypad.h>

const byte rowsCount = 4;
const byte columsCount = 4;
 
char keys[rowsCount][columsCount] = {
   { '1','2','3', 'A' },
   { '4','5','6', 'B' },
   { '7','8','9', 'C' },
   { '#','0','*', 'D' }
};
 
const byte rowPins[rowsCount] = { 26, 25, 24, 23 };
const byte columnPins[columsCount] = { 22, 21, 20, 19 };
 
Keypad keypad = Keypad(makeKeymap(keys), rowPins, columnPins, rowsCount, columsCount);
 

int trigPin_1 = 2;
int echoPin_1 = 3;

int trigPin_2 = 4;
int echoPin_2 = 5;

int trigPin_3 = 6;
int echoPin_3 = 7;

int trigPin_4 = 8;
int echoPin_4 = 9;

int trigPin_5 = 10;
int echoPin_5 = 11;

int trigPin_6 = 12;
int echoPin_6 = 13;

int trigPin_7 = 14;
int echoPin_7 = 15;

int trigPin_8 = 16;
int echoPin_8 = 17;

int alarma = 18;

float velocidad = 0.0343;

long duracion_1, distancia_1;
long duracion_2, distancia_2;
long duracion_3, distancia_3;
long duracion_4, distancia_4;
long duracion_5, distancia_5;
long duracion_6, distancia_6;
long duracion_7, distancia_7;
long duracion_8, distancia_8;

void setup() {
  pinMode(trigPin_1, OUTPUT);
  pinMode(echoPin_1, INPUT);

  pinMode(trigPin_2, OUTPUT);
  pinMode(echoPin_2, INPUT);

  pinMode(trigPin_3, OUTPUT);
  pinMode(echoPin_3, INPUT);

  pinMode(trigPin_4, OUTPUT);
  pinMode(echoPin_4, INPUT);

  pinMode(trigPin_5, OUTPUT);
  pinMode(echoPin_5, INPUT);

  pinMode(trigPin_6, OUTPUT);
  pinMode(echoPin_6, INPUT);

  pinMode(trigPin_7, OUTPUT);
  pinMode(echoPin_7, INPUT);

  pinMode(trigPin_8, OUTPUT);
  pinMode(echoPin_8, INPUT);

  digitalWrite(alarma, LOW);
  
}

void loop() {
  
  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_1, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin_1, LOW);

  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_2, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin_2, LOW);

  digitalWrite(trigPin_3, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_3, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin_3, LOW);

  digitalWrite(trigPin_4, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_4, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin_4, LOW);

  digitalWrite(trigPin_5, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_5, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin_5, LOW);

  digitalWrite(trigPin_6, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_6, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin_6, LOW);

  digitalWrite(trigPin_7, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_7, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin_7, LOW);

  digitalWrite(trigPin_8, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin_8, LOW);
  delayMicroseconds(10);
  digitalWrite(trigPin_8, LOW);
  
  
  duracion_1 = pulseIn(echoPin_1, HIGH);
  distancia_1 = velocidad * duracion_1 / 2;
  
  duracion_2 = pulseIn(echoPin_2, HIGH);
  distancia_2 = velocidad * duracion_2 / 2;

  duracion_3 = pulseIn(echoPin_3, HIGH);
  distancia_3 = velocidad * duracion_3 / 2;
  
  duracion_4 = pulseIn(echoPin_4, HIGH);
  distancia_4 = velocidad * duracion_4 / 2;
  
  duracion_5 = pulseIn(echoPin_5, HIGH);
  distancia_5 = velocidad * duracion_5 / 2;   

  duracion_6 = pulseIn(echoPin_6, HIGH);
  distancia_6 = velocidad * duracion_6 / 2;

  duracion_7 = pulseIn(echoPin_7, HIGH);
  distancia_7 = velocidad * duracion_7 / 2;
  
  duracion_8 = pulseIn(echoPin_8, HIGH);
  distancia_8 = velocidad * duracion_8 / 2;


  char key = keypad.getKey();
 
   if (key == '1') {
      digitalWrite(trigPin_1, LOW);
      digitalWrite(echoPin_1, LOW);
      Serial.println("Has desactivado el SENSOR 1");
   }
   if (key == '2') {
      digitalWrite(trigPin_2, LOW);
      digitalWrite(echoPin_2, LOW);
      Serial.println("Has desactivado el SENSOR 2");
   }
   if (key == '3') {
      digitalWrite(trigPin_3, LOW);
      digitalWrite(echoPin_3, LOW);
      Serial.println("Has desactivado el SENSOR 3");
   }
   if (key == '4') {
      digitalWrite(trigPin_4, LOW);
      digitalWrite(echoPin_4, LOW);
      Serial.println("Has desactivado el SENSOR 4");
   }
   if (key == '5') {
      digitalWrite(trigPin_5, LOW);
      digitalWrite(echoPin_5, LOW);
      Serial.println("Has desactivado el SENSOR 5");
   }
   if (key == '6') {
      digitalWrite(trigPin_6, LOW);
      digitalWrite(echoPin_6, LOW);
      Serial.println("Has desactivado el SENSOR 6");
   }
   if (key == '7') {
      digitalWrite(trigPin_7, LOW);
      digitalWrite(echoPin_7, LOW);
      Serial.println("Has desactivado el SENSOR 7");
   }
   if (key == '8') {
      digitalWrite(trigPin_8, LOW);
      digitalWrite(echoPin_8, LOW);
      Serial.println("Has desactivado el SENSOR 8");
   }
   if (key == '9') {
      digitalWrite(trigPin_1, HIGH);
      digitalWrite(echoPin_1, HIGH);

      digitalWrite(trigPin_2, HIGH);
      digitalWrite(echoPin_2, HIGH);
      
      digitalWrite(trigPin_3, HIGH);
      digitalWrite(echoPin_3, HIGH);
      
      digitalWrite(trigPin_4, HIGH);
      digitalWrite(echoPin_4, HIGH);
      
      digitalWrite(trigPin_5, HIGH);
      digitalWrite(echoPin_5, HIGH);
      
      digitalWrite(trigPin_6, HIGH);
      digitalWrite(echoPin_6, HIGH);
      
      digitalWrite(trigPin_7, HIGH);
      digitalWrite(echoPin_7, HIGH);
      
      digitalWrite(trigPin_8, HIGH);
      digitalWrite(echoPin_8, HIGH);
      
      Serial.println("Has ENCIDIDO todos los sensores");
   }
   if (key == '0') {
      digitalWrite(trigPin_1, LOW);
      digitalWrite(echoPin_1, LOW);

      digitalWrite(trigPin_2, LOW);
      digitalWrite(echoPin_2, LOW);
      
      digitalWrite(trigPin_3, LOW);
      digitalWrite(echoPin_3, LOW);
      
      digitalWrite(trigPin_4, LOW);
      digitalWrite(echoPin_4, LOW);
      
      digitalWrite(trigPin_5, LOW);
      digitalWrite(echoPin_5, LOW);
      
      digitalWrite(trigPin_6, LOW);
      digitalWrite(echoPin_6, LOW);
      
      digitalWrite(trigPin_7, LOW);
      digitalWrite(echoPin_7, LOW);
      
      digitalWrite(trigPin_8, LOW);
      digitalWrite(echoPin_8, LOW);
      
      Serial.println("Has APAGADO todos los sensores");
   }



   

  if(distancia_1 < 20){
    digitalWrite(alarma, HIGH);
    Serial.println("Sensor 1 Activado, verifique distanciamiento");
    delay(5000);    
  }else if(distancia_2 < 20){
    digitalWrite(alarma, HIGH);
    Serial.println("Sensor 2 Activado, verifique distanciamiento");
    delay(5000);  
   }else if(distancia_3 < 20){
    digitalWrite(alarma, HIGH);
    Serial.println("Sensor 3 Activado, verifique distanciamiento");
    delay(5000);  
   }else if(distancia_4 < 20){
    digitalWrite(alarma, HIGH);
    Serial.println("Sensor 4 Activado, verifique distanciamiento");
    delay(5000);  
   }else if(distancia_5 < 20){
    digitalWrite(alarma, HIGH);
    Serial.println("Sensor 5 Activado, verifique distanciamiento");
    delay(5000);  
   }else if(distancia_6 < 20){
    digitalWrite(alarma, HIGH);
    Serial.println("Sensor 6 Activado, verifique distanciamiento");
    delay(5000);  
   }else if(distancia_7 < 20){
    digitalWrite(alarma, HIGH);
    Serial.println("Sensor 7 Activado, verifique distanciamiento");
    delay(5000);  
   }else if(distancia_8 < 20){
    digitalWrite(alarma, HIGH);
    Serial.println("Sensor 8 Activado, verifique distanciamiento");
    delay(5000);  
   }else{
    digitalWrite(alarma,LOW);
    Serial.println("No se detectan objetos/personas cerca");
   }

}
