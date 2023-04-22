#include <Arduino.h>
#include <tensao.h>
#include <rotacao.h>
#include <corrente.h>

/**********************************************************
 * variáveis de intervalo para gerenciar o tempo no super loop
 * ********************************************************
 */
unsigned long tensaoTime = 0;
unsigned long correnteTime = 0;
unsigned long cargaTime = 0;

/**********************************************************
 * Objetos de cada sensor instalado. Verificar as informações
 * nos arquivos header na pasta include e nos arquivos cpp
 * nas pasta src.
 * ********************************************************
 */
Tensao sensorTensao;
Rotacao sensorRotacao;
Corrente sensorCorrente;

void setup() {
	Serial.begin(9600);
	sensorTensao.begin();
	sensorRotacao.begin();
	sensorCorrente.begin();
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
		sensorCorrente.read();
		correnteTime = currentTime;
	}
	
	if ((currentTime - cargaTime) >= 1000)
	{
		/* code */
		cargaTime = currentTime;
	}

	sensorRotacao.loop();
}