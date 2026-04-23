#include <Ultrasonic.h>   // biblioteca para o Sensor Ultrassônico

#define TRIGGER_PIN 3     // Pino Trigger do sensor na porta 3
#define ECHO_PIN   2      // Pino Echo do sensor na porta 2

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

// definindo as portas onde estão conectados os motores
#define IN1 7  // Pino motor A (Direita)
#define IN2 6  // Pino motor A (Direita)
#define IN3 5  // Pino motor B (Esquerda) - adicionado para completar
#define IN4 4  // Pino motor B (Esquerda)

#define ENA 10 // Pino velocidade motor A (Enable A)
#define ENB 11 // Pino velocidade motor B (Enable B)

void setup()
{
    // Definindo os motores como saídas
    pinMode(IN1, OUTPUT);
    pinMode(IN2, OUTPUT);
    pinMode(IN3, OUTPUT);
    pinMode(IN4, OUTPUT);
    pinMode(ENA, OUTPUT);
    pinMode(ENB, OUTPUT);

    // Velocidade dos motores (PWM de 0 a 255)
    analogWrite(ENA, 200);
    analogWrite(ENB, 200);
    delay(1000); // Aguarda 1 segundo antes de iniciar

    Serial.begin(9600); 
}

void loop()
{
    // Robô anda para frente
    robo_frente();

    float dist_cm = distancia(); // Mede a distância do obstáculo
    Serial.println(dist_cm);

    if (dist_cm < 20)   // Se distância menor que 20cm
    {
        decisao();      // Toma a decisão (parar, virar, etc.)
    }

    delay(100);
}

// Função que mede a distância em cm
float distancia()
{
  return ultrasonic.distanceRead();
}

// Função para mover o robô para frente
void robo_frente()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
}

void robo_esquerda()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
}

// Função para parar o robô
void robo_parado()
{
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, LOW);
}

// Função que decide a ação do robô ao encontrar um obstáculo
void decisao()
{
    robo_parado();
    delay(500);
    robo_esquerda();        // Vira à esquerda
    delay(400);             // Ajuste este valor para girar aproximadamente 90 graus
    robo_parado();
    delay(500);
}