#include <corrente.h>

void Corrente::begin()
{
    pinMode(pinCorrente,INPUT);
}

void Corrente::read()
{
    volt =  map(analogRead(pinCorrente),0,1023,0,5);
    //normaliza para sensor ACS758 050B
    volt = volt - 2.5 + 0.007 ;
    //calcula corrente (ACS758 050B varia 40mV / A)
    c_value = volt/0.04;
}