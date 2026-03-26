# Projeto: Monitoramento de Distância com Sensor Ultrassônico

## Objetivo
> [cite_start] Este projeto consiste no desenvolvimento de um sistema autônomo de monitoramento de distância utilizando a plataforma Arduino[cite: 12]. [cite_start]A aplicação emprega um sensor ultrassônico (HC-SR04) integrado a atuadores visuais (LEDs) e sonoros (Buzzer) para responder dinamicamente à proximidade de obstáculos no mundo físico[cite: 13, 21]. 

> [cite_start] Ele representa a evolução de um sistema anterior de sensoriamento analógico (LDR), substituindo-o pela medição digital de tempo de retorno de ondas acústicas (echo)[cite: 14, 20].

## Componentes Utilizados
* [cite_start]1x Placa Arduino Uno [cite: 34]
* [cite_start]1x Sensor Ultrassônico HC-SR04 [cite: 38]
* [cite_start]1x Piezo (Buzzer) [cite: 40]
* [cite_start]4x LEDs (Azul, Verde, Amarelo e Vermelho) [cite: 39]
* [cite_start]5x Resistores [cite: 41]
* [cite_start]14x Jumpers [cite: 36]
* [cite_start]1x Protoboard [cite: 37]

## Esquema de Montagem e Pinos



A integração dos componentes com o microcontrolador segue o mapeamento abaixo:

| Componente | Pino Arduino | Função no Sistema |
| :--- | :---: | :--- |
| **HC-SR04 (Trigger)** | `3` | [cite_start]Emissor do pulso ultrassônico (Saída) [cite: 29] |
| **HC-SR04 (Echo)** | `4` | [cite_start]Receptor do retorno da onda (Entrada) [cite: 29] |
| **LED Azul** | `10` | [cite_start]Acionado junto ao alarme crítico [cite: 59, 68] |
| **LED Verde** | `11` | [cite_start]Indicador de distância segura (>= 200cm) [cite: 61, 68] |
| **LED Amarelo** | `12` | [cite_start]Indicador de atenção (entre 50cm e 200cm) [cite: 62, 68] |
| **LED Vermelho**| `13` | [cite_start]Indicador de alerta (<= 50cm) [cite: 63, 68] |
| **Buzzer** | `2` | [cite_start]Alarme sonoro [cite: 31, 71] |

## Como Funciona a Lógica

[cite_start]O código realiza leituras contínuas disparando um sinal no pino *Trigger* e utilizando a função `pulseIn()` no pino *Echo* para calcular o tempo de viagem do som[cite: 21, 32, 101]. [cite_start]Esse tempo é convertido em centímetros utilizando o fator `0.01723`[cite: 32, 126]. 

[cite_start]Com base nessa conversão, o sistema classifica a distância e aciona as saídas correspondentes[cite: 32]:

1. [cite_start]**Distância Segura (>= 200 cm):** O LED Verde acende[cite: 144].
2. [cite_start]**Atenção (50 cm < Distância <= 200 cm):** O LED Amarelo acende[cite: 145].
3. [cite_start]**Barreira Crítica (<= 50 cm):** O sistema entra em estado de alerta máximo[cite: 15, 16].
   * [cite_start]O LED Vermelho acende[cite: 147].
   * [cite_start]O LED Azul acende[cite: 154].
   * [cite_start]O Buzzer emite um tom contínuo de 1000Hz[cite: 31, 152].

## 🚀 Como Executar

1. Monte o circuito na protoboard seguindo a tabela de pinos e as conexões indicadas acima.
2. Clone o repositório da disciplina:
   ```bash
   git clone [https://github.com/Jhon-Victor-Ramos/robotica-inclusiva-unicap.git](https://github.com/Jhon-Victor-Ramos/robotica-inclusiva-unicap.git)
   ```
3. Navegue até o diretório deste projeto e abra o arquivo .ino na Arduino IDE.
4. Conecte sua placa Arduino Uno ao computador via USB.
5. Na IDE, selecione a placa e a porta correspondente (Ferramentas > Placa e Ferramentas > Porta).
6. Faça o upload (Carregar) do código para o Arduino.
7. Abra o Monitor Serial (taxa de 9600 baud) para visualizar a conversão da distância em centímetros em tempo real.

## Autores

* Equipe de desenvolvimento:
    - Camila Danielle Ramos Torquato 
    - Jhon Victor Ramos Martins 
    - Maria Clara de Oliveira Barbosa 
    - Maria Luiza da Silva Monteiro 
    - Rielly Luiza Duarte da Silva 
