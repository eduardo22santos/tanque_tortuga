#ifndef ROTACAO_H
#define ROTACAO_H
#include <Arduino.h>

#define pinRotacao 2

struct Rotacao
{
    //valor da rotaçao em rpm
    unsigned int rotacao;
    //inicializa o sensor de rotação
    void begin();
    //faz o cálculo da rotação a cada 1 segundo
    void loop();
};

//Faz o somatório de pulsos no attackInterrutp
void callBack();

#endif // ROTACAO_H