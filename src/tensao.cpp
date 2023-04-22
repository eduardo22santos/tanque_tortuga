#include <tensao.h>
void Tensao::begin()
{
	pinMode(A0, INPUT);// configura o pino A0 como pino de entrada para recerber a tensão em bits
}

void Tensao::read() 
{
	tensao_em_bits = analogRead(A0);                        //leitrua da tensão em bits através do pino analógico A0
	tensao_de_entrada = (tensao_em_bits*3.3)/1023.0;       // converte a tensão de entrada de bits para volts
	tensao_medida = tensao_de_entrada/(R2/(R1+R2));        // transforma a tensão de entrada na tensão medida pelo sensor atráves do divisor de tensão
}