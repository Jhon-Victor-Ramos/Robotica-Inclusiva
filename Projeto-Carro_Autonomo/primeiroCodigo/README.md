# Projeto: Robô Autônomo com Prevenção de Obstáculos

## Objetivo
Este projeto implementa a lógica de controle para um robô móvel autônomo. Ele integra a leitura contínua de um sensor ultrassônico com o acionamento de motores DC através de um módulo Ponte H. O robô se desloca para frente por padrão e, ao detectar um obstáculo a menos de 20 cm, executa uma manobra evasiva autônoma, parando e virando à esquerda antes de retomar o seu trajeto livre.

## Componentes Utilizados
* 1x Placa Arduino Uno (ou compatível)
* 1x Sensor Ultrassônico (ex: HC-SR04)
* 1x Módulo Driver de Motor Ponte H (ex: L298N)
* Motores DC com rodas (Chassi de Robô)
* Protoboard e Jumpers
* Fonte de alimentação externa para os motores (ex: Baterias/Pilhas)

## Esquema de Montagem e Pinos

A montagem física no Arduino segue a configuração abaixo, interligando o sensor para a "visão" do robô e a Ponte H para a tração:

| Componente | Pino Arduino | Função no Sistema |
| :--- | :---: | :--- |
| **Sensor - VCC** | `5V` | Alimentação do sensor |
| **Sensor - GND** | `GND` | Aterramento |
| **Sensor - Trigger** | `3` | Emissor do pulso ultrassônico (Saída) |
| **Sensor - Echo** | `2` | Receptor do retorno da onda (Entrada) |
| **Ponte H - IN1** | `7` | Controle de direção do Motor A (Direita) |
| **Ponte H - IN2** | `6` | Controle de direção do Motor A (Direita) |
| **Ponte H - IN3** | `5` | Controle de direção do Motor B (Esquerda) |
| **Ponte H - IN4** | `4` | Controle de direção do Motor B (Esquerda) |
| **Ponte H - ENA** | `10` | Controle de velocidade PWM do Motor A |
| **Ponte H - ENB** | `11` | Controle de velocidade PWM do Motor B |

## Como Funciona a Lógica

O sistema opera de forma cíclica, avaliando o ambiente e controlando os motores:
1. **Configuração Inicial:** O `setup()` define os pinos da Ponte H como saídas e ajusta a velocidade inicial de ambos os motores utilizando PWM (valor de 120, numa escala de 0 a 255) nos pinos *Enable* (ENA e ENB).
2. **Movimentação Padrão:** O robô inicia sua rotina no `loop()` chamando a função `robo_frente()`, que aciona os pinos da Ponte H com os estados lógicos corretos para mover as rodas no sentido frontal.
3. **Sensoriamento Contínuo:** A função `distancia()` utiliza o método nativo `.read()` da biblioteca `Ultrasonic.h` para disparar o pulso, calcular o tempo de retorno e retornar a distância do obstáculo já convertida em centímetros.
4. **Tomada de Decisão:** Se a distância lida for inferior a 20 cm, a função `decisao()` é engatilhada. O sistema:
   * Para os motores (`robo_parado`) por 500ms.
   * Gira para a esquerda (`robo_esquerda`) por 400ms (tempo estimado para uma rotação de aproximadamente 90 graus).
   * Para novamente por 500ms para estabilizar.
   * Finaliza o bloco e o `loop()` recomeça, voltando a andar para frente na nova direção.

## 🚀 Como Executar

1. Monte o circuito conectando o sensor ultrassônico e a Ponte H aos respectivos pinos do Arduino detalhados na tabela. Certifique-se de conectar a alimentação externa adequadamente na Ponte H e compartilhar o GND com o Arduino.
2. Certifique-se de ter a biblioteca **Ultrasonic** (por Erick Simões) instalada no Gerenciador de Bibliotecas da Arduino IDE.
3. Clone o repositório da disciplina:
   ```bash
   git clone [https://github.com/Jhon-Victor-Ramos/robotica-inclusiva-unicap.git](https://github.com/Jhon-Victor-Ramos/robotica-inclusiva-unicap.git)
   ```
4. Abra o arquivo `.ino` correspondente a este projeto na Arduino IDE.
5. Conecte sua placa Arduino ao computador.
6. Selecione a placa e a porta correta na IDE (Ferramentas > Placa / Ferramentas > Porta).
7. Clique em Carregar para transferir o código para o microcontrolador.
8. Posicione o robô no chão, ligue a fonte de alimentação dos motores e observe seu funcionamento autônomo.

## Autores
* Desenvolvido por:
    - Camila Danielle Ramos Torquato
    - Jhon Victor Ramos Martins
    - Maria Clara de Oliveira Barbosa
    - Maria Luiza da Silva Monteiro
    - Rielly Luiza Duarte da Silva
