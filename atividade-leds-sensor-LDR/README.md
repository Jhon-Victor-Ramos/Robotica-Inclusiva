# Projeto: Monitor de Luminosidade com Alarme Sensorial

## Objetivo
Este projeto implementa um sistema de monitoramento de luz ambiente capaz de fornecer feedback visual e sonoro com base na intensidade luminosa. Ele serve como um protótipo para soluções de acessibilidade, alertando usuários (visualmente ou sonoramente) sobre mudanças drásticas na iluminação de um ambiente.

## Componentes Utilizados
* 1x Placa Arduino (Uno/Nano)
* 1x Sensor de Luminosidade (LDR)
* 1x Buzzer
* 4x LEDs (Cores sugeridas: Verde, Amarelo, Vermelho e Branco/Azul para o alarme)
* 4x Resistores (220Ω ou 330Ω) para os LEDs
* 1x Resistor (10kΩ) para o divisor de tensão do LDR
* Protoboard e Jumpers

## Esquema de Montagem e Pinos

A montagem no Arduino segue a seguinte configuração de pinos:

| Componente | Pino Arduino | Função no Sistema |
| :--- | :--- | :--- |
| **LDR** | `A0` | Leitura analógica da luz ambiente |
| **LED 2** | `8` | Indicador de luz baixa |
| **LED 3** | `9` | Indicador de luz média |
| **LED 4** | `10` | Indicador de luz alta |
| **LED 1** | `3` | Alarme visual (pisca em luz extrema) |
| **Buzzer** | `2` | Alarme sonoro |

*Nota: O LDR deve ser montado em um circuito divisor de tensão utilizando o resistor de 10kΩ conectado ao GND.*

## Como Funciona a Lógica

O código faz a leitura constante do pino `A0` e classifica a luminosidade em três estágios:

1. **Luz Baixa (Leitura < 350):** O ambiente está escuro. O LED do pino 8 acende.
2. **Luz Média (Leitura entre 350 e 499):** O ambiente está a meia luz. O LED do pino 9 acende.
3. **Luz Alta/Alerta (Leitura >= 500):** O ambiente está muito claro. O sistema aciona o modo de alerta:
   * O LED do pino 10 acende fixo.
   * O Buzzer emite um tom de 1500Hz.
   * O LED de alarme (pino 3) pisca em intervalos de 500ms.

## Como Executar
1. Monte o circuito na protoboard seguindo a tabela de pinos acima.
2. Abra o arquivo `.ino` deste diretório na **Arduino IDE**.
3. Conecte o Arduino ao computador e selecione a porta correta.
4. Faça o upload do código.
5. Abra o **Monitor Serial** (baud rate `9600`) para acompanhar os valores numéricos captados pelo LDR em tempo real.
