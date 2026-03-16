int valorLDR = 0; 
int pinLed1 = 2, pinLed2 = 3, pinLed3 = 4, pinLed4 = 5, pinLed5 = 6;
int pinLDR = A1; 

void setup() {
  Serial.begin(9600);
  pinMode(pinLed1, OUTPUT);
  pinMode(pinLed2, OUTPUT);
  pinMode(pinLed3, OUTPUT);
  pinMode(pinLed4, OUTPUT);
  pinMode(pinLed5, OUTPUT);
  analogReference(EXTERNAL); 
}

void loop() {
  long soma = 0;
  int amostras = 10; 

  for (int i = 0; i < amostras; i++) {
    soma += analogRead(pinLDR);
    delay(2);
  }
  
  valorLDR = soma / amostras;

  Serial.print("Valor Estabilizado: ");
  Serial.println(valorLDR);

  if(valorLDR >= 950) { 
    digitalWrite(pinLed1, LOW);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else if(valorLDR >= 800) { 
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, LOW);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else if(valorLDR >= 650) { 
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, LOW);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else if(valorLDR >= 500) { 
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, LOW);
    digitalWrite(pinLed5, LOW);
  }
  else if(valorLDR >= 350) { 
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, HIGH);
    digitalWrite(pinLed5, LOW);
  }
  else { 
    digitalWrite(pinLed1, HIGH);
    digitalWrite(pinLed2, HIGH);
    digitalWrite(pinLed3, HIGH);
    digitalWrite(pinLed4, HIGH);
    digitalWrite(pinLed5, HIGH);
  }

  delay(50);
}
