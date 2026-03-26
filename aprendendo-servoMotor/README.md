# Projeto: Sistema de Monitoramento de Proximidade com Dois Estágios de Alerta e Atuador Físico

## Objetivo
Este projeto representa um avanço no sistema de monitoramento com sensor ultrassônico, introduzindo níveis de criticidade no alerta (contínuo vs. intermitente) e a base lógica para controle de um atuador físico (um Servo Motor). É ideal para protótipos de acessibilidade mais complexos ou sistemas de automação, como cancelas automáticas que reagem à proximidade e alertam usuários ao redor.

## Componentes Utilizados
* 1x Placa Arduino Uno
* 1x Sensor Ultrassônico HC-SR04
* 1x Micro Servo Motor (ex: SG90)
* 1x Piezo (Buzzer)
* 4x LEDs (Azul, Verde, Amarelo e Vermelho)
* Resistores (220Ω ou 330Ω) para os LEDs
* Jumpers e Protoboard



## Esquema de Montagem e Pinos

A integração dos componentes com o microcontrolador segue a configuração abaixo:

| Componente | Pino Arduino | Função no Sistema |
| :--- | :--- | :--- |
| **HC-SR04 (Trigger)** | `8` | Emissor do pulso ultrassônico (Saída) |
| **HC-SR04 (Echo)** | `9` | Receptor do retorno da onda (Entrada) |
| **Servo Motor** | `3` | Atuador físico (inicia na posição 0º) |
| **Buzzer** | `2` | Alarme sonoro (Emite 1000Hz) |
| **LED Azul** | `10` | Indicador de alarme extra (crítico e severo) |
| **LED Verde** | `11` | Indicador de distância segura (>= 200cm) |
| **LED Amarelo** | `12` | Indicador de atenção (entre 50cm e 200cm) |
| **LED Vermelho**| `13` | Indicador de barreira rompida (<= 50cm) |

## Como Funciona a Lógica

O sistema mede continuamente a distância em centímetros e classifica o ambiente em diferentes estados de alerta, limpando os estados dos LEDs a cada ciclo para garantir a atualização em tempo real:

1. **Estado Seguro (>= 200 cm):** Apenas o LED Verde é acionado.
2. **Estado de Atenção (50 cm < Distância <= 200 cm):** Apenas o LED Amarelo é acionado.
3. **Estado de Alerta (<= 50 cm):** O LED Vermelho acende. A partir daqui, o sistema avalia o quão perto o obstáculo está para definir o comportamento do alarme (LED Azul + Buzzer):
   * **Alerta Nível 1 (25 cm < Distância <= 50 cm):** O Buzzer toca continuamente e o LED Azul permanece aceso de forma fixa.
   * **Alerta Nível 2 - Crítico (<= 25 cm):** O sistema entra em modo intermitente. O LED Azul pisca e o Buzzer emite bipes espaçados por 500ms, chamando mais atenção para a colisão iminente.
4. **Servo Motor:** A biblioteca `Servo.h` é instanciada e o motor é fixado no pino 3, iniciando na posição 0 graus durante o `setup()`, deixando a estrutura pronta para movimentações futuras baseadas na distância.

## Como Executar

1. Monte o circuito na protoboard seguindo a tabela de pinos. Não esqueça de ligar os pinos de alimentação (VCC/5V e GND) do HC-SR04 e do Servo Motor.
2. Clone o repositório da disciplina:
   ```bash
   git clone [https://github.com/Jhon-Victor-Ramos/robotica-inclusiva-unicap.git](https://github.com/Jhon-Victor-Ramos/robotica-inclusiva-unicap.git)
   ```
3. Navegue até a pasta do projeto e abra o arquivo .ino na Arduino IDE.
4. Conecte sua placa via USB, certificando-se de selecionar a placa e a porta corretas (Ferramentas > Placa / Ferramentas > Porta).
5. Faça o upload do código.
6. Abra o Monitor Serial (taxa de 9600 baud) para verificar as medições de distância impressas na tela a cada ciclo.

## Autores

* Desenvolvido por:
    - Camila Danielle Ramos Torquato 
    - Jhon Victor Ramos Martins 
    - Maria Clara de Oliveira Barbosa 
    - Maria Luiza da Silva Monteiro 
    - Rielly Luiza Duarte da Silva 
