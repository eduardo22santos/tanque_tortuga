#ifndef CORRENTE_H
#define CORRENTE_H
#include <Arduino.h>

#define pinCorrente 10

struct Corrente
{
    float volt;
    float c_value;
    //inicializa o sensor de corrente
    void begin();
    //faz a leitura e cálculo da corrente
    void read();
};

#endif // CORRENTE_H