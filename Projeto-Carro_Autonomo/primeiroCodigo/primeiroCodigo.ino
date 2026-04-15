#include <Ultrasonic.h> // incluindo a biblioteca para o Sensor Ultrassônico

#define TRIGGER_PIN 3 // Pino Trigger do sensor na porta 3
#define ECHO_PIN 2 // Pino Echo do sensor na porta 2

Ultrasonic ultrasonic(TRIGGER_PIN, ECHO_PIN);

// definindo as portas onde estão conectados os motores
#define IN1 7 // Pinos motor A (Direita)
#define IN2 6 // Pinos motor A (Direita)
#define IN3 5 // Pinos motor B (Esquerda) -> Declarado para corrigir o código
#define IN4 4 // Pinos motor B (Esquerda)

#define ENA 10 // Pino velocidade motor A (Enable A)
#define ENB 11 // Pino velocidade motor B (Enable B)

void setup ()
{
  //Definindo os motores como saídas
  pinMode(IN1,OUTPUT); //Saída para motor A
  pinMode(IN2,OUTPUT); //Saída para motor A
  pinMode(IN3,OUTPUT); //Saída para motor B
  pinMode(IN4,OUTPUT); //Saída para motor B
  pinMode(ENA,OUTPUT); //Controle velocidade motor A
  pinMode(ENB,OUTPUT); //Controle velocidade motor B

  // Velocidade dos motores, caso note que seu robô está muito lento, altere os valores.
  analogWrite(ENA,120); //Controle PWM do motor A (0 a 255)
  analogWrite(ENB,120); //Controle PWM do motor B (0 a 255)
  delay(1000); // Aguarda 1 segundo antes de iniciar
}

void loop() // loop principal
{
  //Robô inicia andando para frente
  robo_frente();

  float dist_cm = distancia(); // Declara variável que armazena a distância do obstáculo

  if (dist_cm < 20) // distância menor que 20cm ?
  {
    decisao();
  }

  delay(100); // Pequeno delay para estabilidade da leitura
}

float distancia() //função que mede a distância em cm
{
  // A biblioteca moderna faz toda a conversão de tempo para centímetros automaticamente.
  // Basta usar o método read() que ele retorna a distância em CM por padrão.
  return ultrasonic.read(); 
}

void robo_frente() // função para mover o robô para frente lembre-se da tabela da Ponte H
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void robo_esquerda() //função para mover o robô para esquerda
{
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);
}

void robo_parado() //função para parar o robô
{
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,LOW);
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,LOW);
}

void decisao() //função para decidir a ação do robô
{
  robo_parado();
  delay(500);
  robo_esquerda();
  //esse tempo precisa ser avaliado para que o robô vire por volta de 90 graus
  delay(400); 
  robo_parado();
  delay(500);
}