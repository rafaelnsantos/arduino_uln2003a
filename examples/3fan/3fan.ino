#include "WaterControl.h"
#include "LightControl.h" //controle da luz
#include "TemperatureControl.h" //controle de temperatura(2 ventoinhas)
#include "HumidityControl.h" //controle de umidade
#include "dht.h" //sensor temperatura e umidade
#include <Wire.h> //requerimento ds3231.h
#include "ds3231.h" //relogio

dht dhtInterno(2); //pino do sensor DHT11
HumidityControl umidade(10, true); //pino do rele do umidificador
TemperatureControl temperatura(9, 8); //pino da ventoinha de entrada e saida
LightControl luz(13, true); //pino do rele da luz
WaterControl agua(12, true);

void setup()
{

	
	//Serial.begin(9600);
	umidade.setUmidadeIdeal(70); //humidade a ser alcançada
	umidade.setMargemDeErro(3); //margem de erro: entre 67 e 73
	umidade.begin();

	temperatura.setTemperaturaIdeal(29); //temperatura a ser alcançada
	temperatura.setMargemDeErro(3); //margem de erro: entre 26 e 32
	temperatura.begin();

	DS3231_begin();

	luz.setHorasLigada(9);
	luz.begin();

	agua.setMinutosLigada(5);
	agua.setRegadas(3);
	agua.begin();
}

void loop()
{
	dhtInterno.update();

	umidade.update(dhtInterno.getHumidity());
	
	temperatura.update(dhtInterno.getTemperature());
	
	luz.update(getHour());
	
	agua.update(getTime(), luz);

	delay(2000);
}
