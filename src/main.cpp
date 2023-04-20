#include <Arduino.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), modo, RISING);
}

void loop() {
  
  Serial.println(contador*60);
  contador = 0;
  delay(1000);
}

void modo()
{
  contador++;
}
