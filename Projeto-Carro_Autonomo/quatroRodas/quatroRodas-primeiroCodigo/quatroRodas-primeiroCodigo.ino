#include <Servo.h> // Biblioteca para o servo motor
#include <NewPing.h> // Bibliotec para o sensor ultrassônico

// Pinos de controle do motor na L298N
const int LeftMotorForward = 6;
const int LeftMotorBackward = 7;
const int RightMotorForward = 5;
const int RightMotorBackward = 4;
const int enA = 8;
const int enB = 3;

// Pinos do sensor ultrassônico
#define trig_pin 11
#define echo_pin 12

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;

NewPing sonar(trig_pin, echo_pin, maximum_distance); // Função do sensor ultrassônico
Servo servo_motor; 

void setup(){

  pinMode(RightMotorForward, OUTPUT);
  pinMode(LeftMotorForward, OUTPUT);
  pinMode(LeftMotorBackward, OUTPUT);
  pinMode(RightMotorBackward, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
  
  servo_motor.attach(9); // O pino do servo motor

  servo_motor.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop(){

  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);
  
  if (distance <= 15){
    moveStop();
    delay(300);
    moveBackward();
    delay(300);
    moveStop();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      turnRight();
      moveStop();
    }
    else{
      turnLeft();
      moveStop();
    }
  }
  else{
    moveForward(); 
    
  }
    distance = readPing();
}

int lookRight(){  
  servo_motor.write(50);
  delay(300);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
}

int lookLeft(){
  servo_motor.write(170);
  delay(300);
  int distance = readPing();
  delay(100);
  servo_motor.write(115);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}

void moveStop(){
  
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);
}

void moveForward(){

  if(!goesForward){

    goesForward=true;
    
    digitalWrite(LeftMotorForward, HIGH);
    digitalWrite(RightMotorForward, HIGH);
  
    digitalWrite(LeftMotorBackward, LOW);
    digitalWrite(RightMotorBackward, LOW); 
    digitalWrite(enA,HIGH);
    digitalWrite(enB,HIGH);
  }
}

void moveBackward(){

  goesForward=false;

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);
  
}

void turnRight(){

  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorBackward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);
  
  delay(300);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);
 
  
  
}

void turnLeft(){

  digitalWrite(LeftMotorBackward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);

  delay(300);
  
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  
  digitalWrite(LeftMotorBackward, LOW);
  digitalWrite(RightMotorBackward, LOW);
  digitalWrite(enA,HIGH);
  digitalWrite(enB,HIGH);
}