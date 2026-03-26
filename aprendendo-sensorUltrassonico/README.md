# Projeto: Leitura Base de Distância com Sensor Ultrassônico

## Objetivo
Este projeto implementa a leitura fundamental de um sensor ultrassônico para calcular a distância de objetos próximos. Ele envia um pulso sonoro, mede o tempo de retorno do eco e converte esse intervalo de tempo em unidades de medida reais (centímetros e polegadas). Este código serve como uma base estrutural para testes de sensores e para a criação de projetos mais complexos de robótica móvel e detecção de obstáculos.

## Componentes Utilizados
* 1x Placa Arduino Uno (ou compatível)
* 1x Sensor Ultrassônico (ex: HC-SR04)
* Protoboard e Jumpers

## Esquema de Montagem e Pinos

A montagem física no Arduino segue a configuração abaixo, utilizando pinos digitais separados para disparar o sinal e receber o eco:

| Componente | Pino Arduino | Função no Sistema |
| :--- | :---: | :--- |
| **VCC** | `5V` | Alimentação do sensor |
| **GND** | `GND` | Aterramento |
| **Trigger** | `8` | Emissor do pulso ultrassônico (Saída) |
| **Echo** | `9` | Receptor do retorno da onda (Entrada) |

## Como Funciona a Lógica

O sistema opera convertendo o tempo de viagem do som no ar em distância física:
1. **Geração do Pulso:** A função customizada `readUltrasonicDistance()` configura o pino *Trigger* como saída e emite um pulso `HIGH` de 10 microssegundos para disparar a onda sonora.
2. **Leitura do Tempo:** O pino *Echo* é configurado como entrada. A função nativa `pulseIn(echoPin, HIGH)` mede o tempo (em microssegundos) que o som leva para ir até o obstáculo e voltar ao sensor.
3. **Conversão para Centímetros:** No `loop()`, o tempo de retorno capturado é multiplicado pelo fator `0.01723` (derivado da velocidade do som fracionada pelo trajeto de ida e volta).
4. **Conversão para Polegadas:** O valor em centímetros é dividido pelo fator `2.54`.
5. **Saída:** Os resultados em ambas as unidades de medida são impressos continuamente no Monitor Serial a cada 100 milissegundos.

## 🚀 Como Executar

1. Monte o circuito conectando os pinos de alimentação e os dados (Trigger no pino 8 e Echo no pino 9).
2. Clone o repositório da disciplina:
   ```bash
   git clone [https://github.com/Jhon-Victor-Ramos/robotica-inclusiva-unicap.git](https://github.com/Jhon-Victor-Ramos/robotica-inclusiva-unicap.git)
   ```
3. Abra o arquivo .ino correspondente a este projeto na Arduino IDE.
4. Conecte sua placa Arduino ao computador.
5. Selecione a placa e a porta correta na IDE (Ferramentas > Placa / Ferramentas > Porta).
6. Clique em Carregar para transferir o código para o microcontrolador.
7. Abra o Monitor Serial (configure a taxa de transmissão para 9600 baud) para visualizar as medições em tempo real.

## Autores
* Desenvolvido por:
    - Camila Danielle Ramos Torquato
    - Jhon Victor Ramos Martins
    - Maria Clara de Oliveira Barbosa
    - Maria Luiza da Silva Monteiro
    - Rielly Luiza Duarte da Silva
