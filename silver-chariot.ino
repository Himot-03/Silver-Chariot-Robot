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

Servo servo1;//servo de tracción
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
  servo2.attach(11);//servo de sensor asignado al pin 11

  digitalWrite(s0,HIGH);
  digitalWrite(s1,LOW);
  
  Serial.begin(9600); //inicia la comunicacion serial

}
void loop() {  
servo2.write(80);//angulo del servo del sensor
servo1.write(67);

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
  delay(5);
   if (distance <= 40){ // estructura if para alertar del peligro de colision
  digitalWrite (IN3, LOW);
digitalWrite (IN4, LOW);
delay(5);
  digitalWrite (IN3, HIGH);
digitalWrite (IN4, LOW);
servo2.write(80);
analogWrite(ENB, 90);
delay(10); 
     display.setTextSize(1,1);
  display.setTextColor(WHITE);
  display.setCursor(0, 55);
  display.println("Object near!");
  display.display();
  }
  else{

digitalWrite (IN3, LOW);
digitalWrite (IN4, HIGH);//movimiento del motor de direccion hacia adelante

analogWrite(ENB,500);//velocidad del motor
delay(20); 
 

  }
  
 
display.display();
display.clearDisplay();
 delay(200);
}


 

  



