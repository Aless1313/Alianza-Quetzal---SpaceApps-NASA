#include <DHT11.h>
#include <SoftwareSerial.h>
#include <Servo.h>

SoftwareSerial gps(9,10);

Servo servoMotorGiro;
Servo servoMotorRotacion;
Servo servoMotorUpDown;
Servo servoMotorAgarraSuelta;

int temperaturaHumedad = 11;
DHT11 dht11(temperaturaHumedad);

int ledUV = 3;
int tomarFoto = 8;
char accion;

char datosGPS;

int rueda1_Adelante = 12;
int rueda1_Atras = 13;
int rueda2_Adelante = 14;
int rueda2_Atras = 15;
int velocidadRuedas = 255;



void setup() {
  pinMode(ledUV, OUTPUT);
  pinMode(tomarFoto, OUTPUT);
  servoMotorGiro.attach(4);
  servoMotorRotacion.attach(5);
  servoMotorUpDown.attach(6);
  servoMotorAgarraSuelta.attach(7);
  gps.begin(9600);
  pinMode(rueda1_Adelante, OUTPUT);
  pinMode(rueda1_Atras, OUTPUT);
  pinMode(rueda2_Adelante, OUTPUT);
  pinMode(rueda2_Atras, OUTPUT);
  
  
  Serial.begin(9600);
}

void loop() {
  int err;
  float temperatura, humedad;
  if((err = dht11.read(humedad,temperatura))==0){
      Serial.println("Temperatura ambiente actual: ");
      Serial.println(temperatura);
      Serial.println("Humedad ambiente actual:");
      Serial.println(humedad);
      Serial.println(" %");
    }else{
        Serial.println("ERROR al leer datos con el sensor de humedad/temperatura");
      }
  if(Serial.available()>0){
      accion = Serial.read();
      if(accion == 'a'){
          digitalWrite(ledUV, HIGH);
          Serial.println("Escaneando con luz UV");
          delay(10000);
        }
      if(accion == 'b'){
          digitalWrite(ledUV, LOW);
          Serial.println("Has apagado la luz UV");
        }
      if(accion == 'c'){
          servoMotorGiro.write(0);
          Serial.println("Giraste el brazo hacia la derecha");
        }
        if(accion == 'd'){
          servoMotorGiro.write(90);
          Serial.println("Giraste el brazo hacia el centro");
        }
        if(accion == 'e'){
          servoMotorGiro.write(180);
          Serial.println("Giraste el brazo hacia la izquierda");
        }
        if(accion == 'f'){
          servoMotorRotacion.write(0);
          Serial.println("Rotaste el brazo 0 grados");
        }
        if(accion == 'g'){
          servoMotorRotacion.write(90);
          Serial.println("Rotaste el brazo 90 grados");
        }
        if(accion == 'h'){
          servoMotorRotacion.write(180);
          Serial.println("Rotaste el brazo 180 grado");
        }
        if(accion == 'i'){
          servoMotorUpDown.write(0);
          Serial.println("Has elevado el brazo");
        }
        if(accion == 'j'){
          servoMotorRotacion.write(180);
          Serial.println("Has bajado el brazo");
        }
        if(accion == 'k'){
          servoMotorAgarraSuelta.write(0);
          Serial.println("Cerraste el brazo");
        }
        if(accion == 'l'){
          servoMotorAgarraSuelta.write(180);
          Serial.println("Abriste el brazo");
        }
        if(accion == 'm'){
          digitalWrite(tomarFoto, HIGH);
          Serial.println("Has tomado una foto");
        }
        if(accion == 'n'){
          digitalWrite(rueda1_Adelante, velocidadRuedas);
          digitalWrite(rueda2_Adelante, velocidadRuedas);
          digitalWrite(rueda1_Atras, 0);
          digitalWrite(rueda2_Atras, 0);
          Serial.println("Robot Avanzando");
        }
        if(accion == 'o'){
          digitalWrite(rueda1_Adelante, 0);
          digitalWrite(rueda2_Adelante, 0);
          digitalWrite(rueda1_Atras, 0);
          digitalWrite(rueda2_Atras, 0);
          Serial.println("Robot Detenido");
        }
        if(accion == 'p'){
          digitalWrite(rueda1_Adelante, 0);
          digitalWrite(rueda2_Adelante, 0);
          digitalWrite(rueda1_Atras, velocidadRuedas);
          digitalWrite(rueda2_Atras, velocidadRuedas);
          Serial.println("Robot Avanzando");
        }
        if(accion == 'q'){
          digitalWrite(rueda1_Adelante, velocidadRuedas);
          digitalWrite(rueda2_Adelante, 0);
          digitalWrite(rueda1_Atras, 0);
          digitalWrite(rueda2_Atras, 0);
          Serial.println("Robot Girando Hacia La Izquierda");
        }
        if(accion == 'r'){
          digitalWrite(rueda1_Adelante, 0);
          digitalWrite(rueda2_Adelante, velocidadRuedas);
          digitalWrite(rueda1_Atras, 0);
          digitalWrite(rueda2_Atras, 0);
          Serial.println("Robot Girando Hacia La Izquierda");
        }
        


        
          
    }
    if(gps.available()){
        datosGPS = gps.read();
        Serial.println("Ubicacion/Coordenadas actuales:" + datosGPS);
      }else{
          Serial.println("Error al leer el modulo GPS, verificar conexiones");
        }
}
