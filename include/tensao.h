#ifndef TENSAO_H
#define TENSAO_H
#include <Arduino.h>

#define A0 13

struct Tensao
{
    int tensao_em_bits = 0;        //variavel que irá receber o sinal de tensao em bits
    float tensao_de_entrada = 0.0; //variavel que irá guardar o valor de tensão de entrada
    float tensao_medida = 0.0;     // variavael que ira guardar a tensão medida pelo sensor
    float R1 = 32000.0;            // valor do resistor 1 em ohms
    float R2 = 7000.0;             // valor do resistor 2 em ohms
    
    // Inicializa o sensor de tensão
    void begin(); 
    // faz a leitura do sensor
    void read();
};
#endif // TENSAO_H