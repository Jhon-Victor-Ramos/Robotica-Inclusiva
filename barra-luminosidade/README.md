# Projeto: Medidor Progressivo de Luminosidade

## Objetivo
Este projeto cria um indicador visual progressivo (estilo gráfico de barras) da intensidade de luz do ambiente utilizando múltiplos LEDs. Diferente de um acionamento simples, o código implementa um **filtro de média de amostras** para estabilizar a leitura do sensor, evitando variações bruscas (flickering). No contexto da Robótica Inclusiva, pode servir como um medidor tátil-visual contínuo para indicar a transição de iluminação de um espaço.

## Componentes Utilizados
* 1x Placa Arduino (Uno/Nano)
* 1x Sensor de Luminosidade (LDR)
* 5x LEDs (Podem ser de cores variadas para indicar a escala, ex: Verde, Amarelo, Vermelho)
* 5x Resistores (220Ω ou 330Ω) para os LEDs
* 1x Resistor (10kΩ) para o divisor de tensão do LDR
* Protoboard e Jumpers

## Esquema de Montagem e Pinos

| Componente | Pino Arduino | Função no Sistema |
| :--- | :--: | :--- |
| **LDR** | `A1` | Leitura analógica da luz ambiente |
| **LED 1** | `2` | Acende no primeiro nível de escuridão |
| **LED 2** | `3` | Acende no segundo nível de escuridão |
| **LED 3** | `4` | Acende no terceiro nível de escuridão |
| **LED 4** | `5` | Acende no quarto nível de escuridão |
| **LED 5** | `6` | Acende no nível máximo de escuridão |

> *(Atenção: O código original utiliza `analogReference(EXTERNAL);`. Certifique-se de fornecer uma tensão de referência no pino AREF, ou remova a linha do código para utilizar os 5V padrão da placa).*

## Como Funciona a Lógica

1. **Estabilização do Sinal:** A cada ciclo, o Arduino realiza 10 leituras rápidas do pino `A1` (com um intervalo de 2ms entre elas) e calcula a média. Isso gera o `valorLDR` estabilizado, imune a pequenas flutuações de luz ou ruído elétrico.
2. **Escala Progressiva (Bar Graph):** * **Luz muito forte (>= 950):** Todos os LEDs apagados.
   * **Conforme a luz diminui:** Os LEDs vão acendendo um a um, em cascata (pinos 2, depois 3, depois 4...).
   * **Escuridão total (< 350):** Todos os 5 LEDs ficam acesos.

## Como Executar
1. Monte o circuito na protoboard.
2. Clone o repositório e abra o arquivo `.ino` na **Arduino IDE**.
3. Verifique a necessidade do pino `AREF` conforme explicado acima.
4. Conecte sua placa e faça o upload (`Ctrl + U`).
5. Abra o **Monitor Serial** (`9600 baud`) para ver a mensagem "Valor Estabilizado:" acompanhada da leitura processada em tempo real.
