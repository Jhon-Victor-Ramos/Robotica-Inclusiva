#include <Servo.h>
#define TRIGGER_PIN 8
#define ECHO_PIN 9
#define LEDS_QUANTITY 4

Servo myServo;

/* azul: 10
 * verde: 11
 * amarelo: 12
 * vermelho: 13
 */
int leds[LEDS_QUANTITY] = {10, 11, 12, 13}; 
int buzzer = 2;

double inches = 0;
double cm = 0;

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);
  
  pinMode(echoPin, INPUT);
  
  return pulseIn(echoPin, HIGH); 
}

void setup() {
  Serial.begin(9600);
  
  for (int i = 0; i < LEDS_QUANTITY; i++) {
    pinMode(leds[i], OUTPUT);
  }
  
  pinMode(buzzer, OUTPUT);

  myServo.attach(3);
  myServo.write(0);
}

void loop() {
  cm = 0.01723 * readUltrasonicDistance(TRIGGER_PIN, ECHO_PIN);
  // inches = (cm / 2.54);
  
  Serial.print("Distancia: ");
  Serial.print(cm);
  Serial.println(" cm");

  for (int i = 0; i < LEDS_QUANTITY; i++) {
    digitalWrite(leds[i], LOW);
  }

  
  /* azul: 10 -> 0
  * verde: 11 -> 1
  * amarelo: 12 -> 2
  * vermelho: 13 -> 3
  */
  if (cm >= 200)  digitalWrite(leds[1], HIGH);
  if (cm > 50 && cm <= 200)  digitalWrite(leds[2], HIGH);
  if (cm <= 50)  digitalWrite(leds[3], HIGH);

  if (cm <= 50 && cm > 25) {
    tone(buzzer, 1000); 
    digitalWrite(leds[0], HIGH);
  } 
  else if (cm <= 25) {
    tone(buzzer, 1000); 
    digitalWrite(leds[0], HIGH);
    delay(500);
    digitalWrite(leds[0], LOW);
    noTone(buzzer);     
  } 
  else {
    noTone(buzzer);
  }
  
  delay(100);
}