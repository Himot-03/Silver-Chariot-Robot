#include <Servo.h>
#include <Wire.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

#define OLED_WIDTH 128//tamaño de la pantalla OLED
#define OLED_HEIGHT 64
#define OLED_ADDR 0x3C
Adafruit_SSD1306 display(OLED_WIDTH, OLED_HEIGHT);

const int trigPin = 9;// pin trig del sensor ultrasonico
const int echoPin = 10;//pin echo del sensor ultrasonico

long duration;//duracion del utrasonido
int distance;//distancia recorrida por este

int Rojo_Frec = 0;//variables RGB del sensor de color
int Verde_Frec = 0;
int Azul_Frec = 0;

Servo servo1;//servo de dirección
Servo servo2;//servo de sensor

int IN3 = 5;//controlador L298N
int IN4 = 4;//de motor
int ENB = 3;//de direccion

const int s0 = 12;//sensor de color
const int s1 = 13;  
const int s2 = 7;  
const int s3 = 6;  
const int out = 2;  

void setup() {

  pinMode(IN4, OUTPUT);//controlador L298N de salida
  pinMode(IN3, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(s0, OUTPUT);//sensor de color
  pinMode(s1, OUTPUT);
  pinMode(s2, OUTPUT);
  pinMode(s3, OUTPUT);
  pinMode(out, INPUT);

  pinMode(trigPin, OUTPUT); // pin trig del sensor ultrasonico en salida
  pinMode(echoPin, INPUT); //pin echo del sensor ultrasonico en entrada
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();

  servo1.attach(8);//servo de traccion asignado al pin 8
  servo2.attach(11);
  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);
  
  Serial.begin(9600); //inicia la comunicacion serial

}
void LeftWay(void){
   if (Rojo_Frec > 35 && Verde_Frec < 40 && Azul_Frec < 56){
        digitalWrite (IN3,HIGH);
     digitalWrite (IN4, LOW);
     analogWrite(ENB, 150);
     delay(1800);
  servo1.write(69);
digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH); //movimiento del motor de direccion hacia adelante...
analogWrite(ENB,90); //velocidad del motor
delay(1000); 
servo1.write(45);
digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH); //movimiento del motor de direccion hacia adelante...
analogWrite(ENB,150); //velocidad del motor
delay(900);
/////////////////////////////////////////////////////////////
//Giro hacía la izquierda/////
servo1.write(95); 
digitalWrite (IN3, LOW); 
digitalWrite (IN4, HIGH); //movimiento del motor de direccion hacia adelante
delay(800);
///////////////////////////////////////////////////////////////
servo1.write(69);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
analogWrite(ENB,90);
delay(1000);
   }
}
void RightWay(void) {
   if (Rojo_Frec < 31 && Verde_Frec > 72 && Azul_Frec > 58){
     digitalWrite (IN3,HIGH);
     digitalWrite (IN4, LOW);
     analogWrite(ENB, 150);
     delay(1800);
  servo1.write(69);
digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH); //movimiento del motor de direccion hacia adelante...
analogWrite(ENB,90); //velocidad del motor
delay(1000); 
servo1.write(100);
digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH); //movimiento del motor de direccion hacia adelante...
analogWrite(ENB,150); //velocidad del motor
delay(1500);
/////////////////////////////////////////////////////////////
//Giro hacía la izquierda/////
servo1.write(45); 
digitalWrite (IN3, LOW); 
digitalWrite (IN4, HIGH); //movimiento del motor de direccion hacia adelante
delay(1300);
///////////////////////////////////////////////////////////////
servo1.write(69);
digitalWrite(IN3, LOW);
digitalWrite(IN4, HIGH);
analogWrite(ENB,90);
delay(1000);
   }
}
void ColorSens(void) {
                          // Configura el filtor ROJO para tomar lectura
  digitalWrite(s2,LOW);
  digitalWrite(s3,LOW);
  delay(100);
  Rojo_Frec= pulseIn(out, LOW);
  Serial.print(" R= "); Serial.print(Rojo_Frec);
  delay(100);
                            // Configura el filtor VERDE para tomar lectura
  digitalWrite(s2,HIGH);
  digitalWrite(s3,HIGH);
  delay(100);
  Verde_Frec = pulseIn(out, LOW);
  Serial.print(" V= "); Serial.print(Verde_Frec);
  delay(100);
                           // Configura el filtor AZUL para tomar lectura
  digitalWrite(s2,LOW);
  digitalWrite(s3,HIGH);
  delay(100);
  Azul_Frec = pulseIn(out, LOW);
  Serial.print(" A= "); Serial.print(Azul_Frec);
  delay(100);

                  //Valores obtenidos en la calibracion del sensor, son propios de cada usuario 
                  
 if (Rojo_Frec < 31 && Verde_Frec > 72 && Azul_Frec > 58)  Serial.print(" . *** ROJO **");
 if (Rojo_Frec > 35 && Verde_Frec < 40 && Azul_Frec < 56)  Serial.print(" . *** VERDE **");
 display.setTextSize(1);
 display.setCursor(0, 11);
  display.setTextColor(WHITE);
   Serial.println("*");
 if (Rojo_Frec < 31 && Verde_Frec > 72 && Azul_Frec > 58)  display.print("Color Rojo >:(");
 if (Rojo_Frec > 35 && Verde_Frec < 40 && Azul_Frec < 56)  display.print("Color Verde :D");
 
display.display();
display.clearDisplay();
 delay(200);
}

void Dangerstate(void) //función de Detección de obstáculos
{
    if (distance >= 5 && distance <= 35) {
        digitalWrite (IN3, HIGH);
        digitalWrite (IN4, LOW);
        analogWrite(ENB, 70); // Velocidad reducida para acercarse lentamente
        delay(100);
        
        digitalWrite (IN3, LOW);
        digitalWrite (IN4, HIGH);
        analogWrite(ENB, 10); // Mantener la misma velocidad
        delay(1);
        
        display.setTextSize(1, 1);
        display.setTextColor(WHITE);
        display.setCursor(0, 55);
        display.println("Object near!");
        display.display();
    } else if (distance <= 4) {
        digitalWrite (IN3, HIGH);
        digitalWrite (IN4, LOW);
        analogWrite(ENB, 0); // Detener el motor
        delay(100); // Mantener detenido durante 0.1 segundos para evitar colisión
    } else {
        digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, 83); // Mantener una velocidad constante cuando no hay peligro
    }
}
void Corner(void){
   if (distance = 100) {
    // Gira el servo a 0 grados
    servo2.write(0);
    delay(1000); // Espera 1 segundo para estabilizar la posición
    
    // Vuelve a medir la distancia
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    long distance0 = duration * 0.034 / 2;
    
    // Gira el servo a 180 grados
    servo2.write(180);
    delay(1000); // Espera 1 segundo para estabilizar la posición
    
    // Vuelve a medir la distancia
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    long distance180 = duration * 0.034 / 2;

    // Compara las distancias y realiza una acción en base a esto
    if (distance0 > distance180) {
      servo1.write(60);
      digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, 150); 
        delay(4000);
    } else {
      servo1.write(30);
      digitalWrite(IN3, LOW);
        digitalWrite(IN4, HIGH);
        analogWrite(ENB, 150); 
        delay(4000);
    }
}
}
void loop() {  
servo1.write(69);
servo2.write(80);

digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(2);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2; // se multiplica la duracion por la velocidad del sonido y se divide entre 2 para calcular la distancia del objeto mediante el sensor ultrasonico

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("distance");
  display.display();
      display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 8);
  display.println(distance);
  display.display();
  display.clearDisplay(); //impresion de la distancia del objeto frente al sensor en la pantalla OLED
  delay(0);
Dangerstate();
ColorSens();
RightWay();
Corner();
delay(0);

display.display();
display.clearDisplay();
 delay(200);

}



 

  



