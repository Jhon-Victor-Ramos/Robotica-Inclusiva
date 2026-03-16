#define LEDS_QUANTITY 4
int leds[LEDS_QUANTITY] = {3, 8, 9, 10};

int ldr = A0;
int intensity = 0;
int buzzer = 2;

void setup() {
  for (int i = 0; i < LEDS_QUANTITY; i++)
    pinMode(leds[i], OUTPUT);
  pinMode(ldr, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int valorldr = analogRead(ldr);
  Serial.println(valorldr);

  if (valorldr < (100 * 3.5)) {
    for (int i = 0; i < LEDS_QUANTITY; i++)
      digitalWrite(leds[i], LOW);
    digitalWrite(leds[1], HIGH);
  }
  else if (valorldr >= (100 * 3.5) && valorldr < 500 ) {
    for (int i = 0; i < LEDS_QUANTITY; i++)
      digitalWrite(leds[i], LOW);
    digitalWrite(leds[2], HIGH);
  }
  else if (valorldr >= 500 ) {
    for (int i = 0; i < LEDS_QUANTITY; i++)
      digitalWrite(leds[i], LOW);
    digitalWrite(leds[3], HIGH);
    tone(buzzer, 1500);
    digitalWrite(leds[0], HIGH);
    delay(500);
    digitalWrite(leds[0], LOW);
    noTone(buzzer);
    delay(250);
  }
}
