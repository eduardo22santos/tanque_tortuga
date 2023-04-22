#include <Arduino.h>
#include <tensao.h>
#include <rotacao.h>

/**********************************************************
 * variáveis de intervalo para gerenciar o tempo no super loop
 * ********************************************************
 */
unsigned long tensaoTime = 0;
unsigned long correnteTime = 0;
unsigned long cargaTime = 0;


Tensao sensorTensao;
Rotacao sensorRotacao;

void setup() {
	Serial.begin(9600);
	sensorTensao.begin();
	sensorRotacao.begin();
}

void loop() {
	unsigned long currentTime = millis();

	if((currentTime - tensaoTime) >= 1000)
	{
		sensorTensao.read();
		tensaoTime = currentTime;
	}

	if ((currentTime - correnteTime) >= 1000 )
	{
		/* code */
	}
	
	if ((currentTime - cargaTime) >= 1000)
	{
		/* code */
	}

	sensorRotacao.loop();
}