/*https://www.makeblock.es/soporte/librerias_makeblock_arduino/

Para incluir la libreria: #include "MeMCore.h"

Entradas y salidas digitales: 
pinMode()->configura el pin con una entrada o salida
digitalWrite()->escribe un valor HIGH o LOW en el pin digital 
digitalRead()->lee el valor del pin correspondiente como HIGH o LOW

Entradas y salidas analogicas:
analogRead()->lee el valor del pin analogico
analogWrite()->escribe un valor analogico al pin

Variables:
const int -> constante entera
int
float
bool...

Clases
MeRGBLed->led RGB del robot (solo se usa para MeBot)
MeDCMotor->motor
Puertos:       Pines SLOT1, SLOT2
PORT_1               D11, D12
PORT_2               D9, D10
PORT_3               A2, A3
PORT_4               A0, A1
PORT_6               D8, D6
PORT_7               A7, D13
PORT_8               D8, A6
PORT_9               D6, D7
PORT_10              D5, D4
M1                   D6, D7
M2                   D5, D4

Componente               Pin asociado
Sensor de luz             A6
Buzzer                    D8
Pulsador                  A7
LEDS RGB                  D13
Motro 1                   D6, D7
Motor 2                   D4, D5
Emisor de infrarrojos     D3
Receptor de infrarrojos   D2
*/
/*Sesion 1 prender un led digital
#include "MeMCore.h"

int LED = 13;
void setup() {
 
  // poner el pin 13 (LED) como salida
  pinMode(LED, OUTPUT);
  //pinMode(7, INPUT);
}

void loop() {
  
  //encender el LED
  digitalWrite(LED, HIGH);
  delay(1000);
  //apagar el LED
  digitalWrite(LED, LOW);
  delay(1000);
}
*/
/*Sesion 2 prender un led rgb
#include "MeMCore.h"

MeRGBLed led(PORT_7);
int rojod;
int verded;
int azuld;
int rojoi;
int verdei;
int azuli;
void setup() {
  rojod = 255;
  verded = 93;
  azuld = 162;
  rojoi = 255;
  verdei = 131;
  azuli = 40;
}
void loop() {
  led.setColorAt(0,rojod,verded,azuld); //led derecho,red,green,blue -> colores desde el 0-255
  led.setColorAt(1,rojoi,verdei,azuli); //led izquierdo,red,green,blue
  led.show();
}
*/
/*Sesion 3 secuencia de led rgb
#include "MeMCore.h"

MeRGBLed led(PORT_7);
int rojoD;
int verdeD;
int azulD;

int rojoI;
int verdeI;
int azulI;

void setup(){
  rojoD = 255;
  verdeD = 0;
  azulD = 0;

  rojoI = 0;
  verdeI = 255;
  azulI = 0;
}
void loop(){
  led.setColorAt(0,rojoD,verdeD,azulD); //led derecho,red,green,blue -> colores desde el 0-255
  led.setColorAt(1,rojoI,verdeI,azulI); //led izquierdo,red,green,blue
  led.show();
  delay(1000);
  rojoD = rojoD -40;
  verdeI = verdeI +40;

}
*/
/*Sesion 4 motor
#include "MeMCore.h"

MeDCMotor motor1(M1);
MeDCMotor motor2(M2);

void setup(){

}
void loop(){
  motor1.run(-100); //mover hacia adelante el motor1
  motor2.run(100); //mover hacia adelante el motor2
  delay(1000);
  motor1.run(100); //mover hacia adelante el motor1
  motor2.run(-100); //mover hacia adelante el motor2
  delay(1000);
  motor1.stop();
  motor2.stop();
  delay(1000);
}
*/
/*Secion 5 condicional (if), y bucle (for)
#include "MeMCore.h"

const int led = 13;
bool estado = true;

void setup(){
  pinMode(led,OUTPUT);
  
}
void loop(){
  if(estado){
    estado = false;
    for(int n=0; n<5;n++){
      digitalWrite(led,HIGH);
      delay(1000);
      digitalWrite(led,LOW);
      delay(1000);
    }

  }else{
    digitalWrite(led,LOW);
  }

}
*/
/*Sesion 6 bucle (while, do while)
#include "MeMCore.h"

const int led = 13;
bool estado = true;
int n;
void setup(){
  pinMode(led,OUTPUT);
  
}
void loop(){
  if(estado){
    estado = false;
    n=0;
    // for(int n=0; n<5;n++){
    //   digitalWrite(led,HIGH);
    //   delay(1000);
    //   digitalWrite(led,LOW);
    //   delay(1000);
    // }
    // while(n<5){
    //   digitalWrite(led,HIGH);
    //   delay(1000);
    //   digitalWrite(led,LOW);
    //   delay(1000);
    //   n++;      
    // }
    do{
      digitalWrite(led,HIGH);
      delay(1000);
      digitalWrite(led,LOW);
      delay(1000);
      n++;   
    }while(n<5);

  }else{
    digitalWrite(led,LOW);
  }

}
*/
/*Sesion 7 condicional para bucle
#include "MeMCore.h"

const int led = 13;
bool estado = true;
int n = 0;

void setup(){
  pinMode(led,OUTPUT);
  
}
void loop(){

 
  if(n<5){
    digitalWrite(led,HIGH);
    delay(1000);
    digitalWrite(led,LOW);
    delay(1000);
    n++;     
  }else{
    digitalWrite(led,LOW);
    delay(5000);
    n=0;
  }
  
  
}
*/
/*Sesion 7 monitor serial leer datos de mbot
//enviar informacion desde mbot al monitor serial

#include "MeMCore.h"

MeRGBLed ledRGB(PORT_7);
//int valores superiores a 255
uint8_t rojo; //valores entre 0-255
uint8_t verde;
uint8_t azul; 

void setup(){
  Serial.begin(9600); //iniciar el puerto serie para enviar y recivir informacion

}
void loop(){
  rojo=random(0,255); //genera un numero aleatorio entre 0-255
  verde=random(0,255);
  azul=random(0,255);

  ledRGB.setColorAt(0,rojo,verde,azul);
  ledRGB.show();

  Serial.print("Rojo: ");
  Serial.println(rojo);
  Serial.print("Verde: ");
  Serial.println(verde);
  Serial.print("Azul: ");
  Serial.println(azul);
  Serial.println("\n");  
  delay(5000);


}
*/
