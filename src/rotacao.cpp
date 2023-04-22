#include <rotacao.h>

unsigned long rotacaoTime = 0;
unsigned int numeroDePulsos = 0;

void Rotacao::begin()
{
    pinMode(pinRotacao,INPUT);
    attachInterrupt(digitalPinToInterrupt(pinRotacao),callBack, RISING);
}

void Rotacao::loop()
{
    if ((millis() - rotacaoTime)>= 1000)
    {
        rotacao = numeroDePulsos * 60;
        numeroDePulsos = 0;
        rotacaoTime = millis();
    }
}

void callBack()
{
    numeroDePulsos++;
}