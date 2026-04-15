# Projeto: Carro Autônomo - Robótica Inclusiva

## Visão Geral
Este repositório contém o código-fonte, a documentação e os diagramas do projeto **Carro Autônomo**, desenvolvido como parte das atividades da disciplina/extensão de **Robótica Inclusiva** na UNICAP. 

O objetivo central do projeto é projetar, montar e programar um robô móvel capaz de navegar de forma autônoma por um ambiente, tomando decisões em tempo real com base em leituras de sensores para evitar colisões e superar obstáculos. O projeto serve como uma aplicação prática de conceitos de hardware, eletrônica básica, lógica de programação (C/C++) e sistemas embarcados.

## Estrutura do Repositório

O projeto é modularizado para facilitar o estudo e a evolução do código. Cada diretório contém uma etapa ou funcionalidade específica do robô:

* **`/primeiro-codigo`**: Contém a implementação da lógica base de movimentação do chassi e a rotina inicial de prevenção de obstáculos utilizando um Sensor Ultrassônico e a Ponte H. (Consulte o README interno desta pasta para detalhes de montagem e pinagem).
* *(Mais pastas podem ser adicionadas aqui conforme o projeto evoluir, como controle via Bluetooth, seguidores de linha, etc.)*

## Hardware Base
A arquitetura de hardware do projeto foi pensada para ser acessível e de fácil montagem, utilizando componentes clássicos do ecossistema Arduino:

* **Microcontrolador:** Placa Arduino Uno (ou compatível)
* **Locomoção:** Chassi de Robô (2WD ou 4WD) com Motores DC 3V-6V
* **Driver de Potência:** Módulo Ponte H dupla L298N (para controle de sentido e velocidade via PWM)
* **Sensoriamento:** Sensor Ultrassônico HC-SR04 (para "visão" e cálculo de distância)
* **Alimentação:** Suporte para pilhas AA ou baterias Li-ion (ex: 18650) para fornecer corrente adequada aos motores separadamente da placa lógica.
* **Diversos:** Protoboard, Jumpers (M-M, M-F, F-F) e fita isolante/dupla face.

## Pré-requisitos de Software

Para compilar e modificar os códigos deste projeto, você precisará configurar o seu ambiente de desenvolvimento:

1.  **Arduino IDE:** Baixe e instale a versão mais recente da [Arduino IDE](https://www.arduino.cc/en/software).
2.  **Dependências:** O projeto utiliza bibliotecas externas que precisam ser instaladas via Gerenciador de Bibliotecas da IDE:
    * `Ultrasonic` (Autor: Erick Simões) - Utilizada para abstrair o cálculo de tempo/distância do sensor HC-SR04.

## 🚀 Como Utilizar este Repositório

1.  Faça o clone do repositório para a sua máquina local:
    ```bash
    git clone [https://github.com/Jhon-Victor-Ramos/robotica-inclusiva-unicap.git](https://github.com/Jhon-Victor-Ramos/robotica-inclusiva-unicap.git)
    ```
2.  Navegue até a pasta do módulo que deseja testar (ex: `cd robotica-inclusiva-unicap/Projeto-Carro_Autonomo/primeiro-codigo`).
3.  Abra o arquivo `.ino` correspondente na Arduino IDE.
4.  Realize as ligações de hardware conforme documentado no README da respectiva pasta.
5.  Conecte o Arduino via USB, selecione a porta correta na IDE e faça o upload (`Ctrl + U`).

## Equipe Desenvolvedora
Projeto construído colaborativamente por estudantes de Computação e áreas afins:

* Camila Danielle Ramos Torquato
* Jhon Victor Ramos Martins
* Maria Clara de Oliveira Barbosa
* Maria Luiza da Silva Monteiro
* Rielly Luiza Duarte da Silva
