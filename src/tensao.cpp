#include <tensao.h>

#define A0 0

int tensao_em_bits = 0;        //variavel que irá receber o sinal de tensao em bits
float tensao_de_entrada = 0.0; //variavel que irá guardar o valor de tensão de entrada
float tensao_medida = 0.0;     // variavael que ira guardar a tensão medida pelo sensor
float R1 = 32000.0;            // valor do resistor 1 em ohms
float R2 = 7000.0;             // valor do resistor 2 em ohms
      


void setup() {
  Serial.begin(9600);         //inicia a serial
  pinMode(A0, INPUT);         // configura o pino A0 como pino de entrada para recerber a tensão em bits
}

void loop() 
{
 tensao_em_bits = analogRead(A0);                        //leitrua da tensão em bits através do pino analógico A0
 tensao_de_entrada = (tensao_em_bits*3.3)/1023.0;       // converte a tensão de entrada de bits para volts
 tensao_medida = tensao_de_entrada/(R2/(R1+R2));        // transforma a tensão de entrada na tensão medida pelo sensor atráves do divisor de tensão

 Serial.print("tensao medida: ");                      // exibe a tensão medida
 Serial.print(tensao_medida);
 Serial.println(" Volt(s)");
 delay(500); 

}