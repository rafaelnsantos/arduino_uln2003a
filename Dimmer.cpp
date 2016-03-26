// 
// 
// 

#include "Dimmer.h"
Dimmer::Dimmer(){}
/*
PWM pin
*/
Dimmer::Dimmer(int p)
{
	pin = p;
}

void Dimmer::begin(){
	pinMode(pin, OUTPUT);
}
void Dimmer::setPin(int p){
	pin = p;
}
int Dimmer::getPin(){
	return pin;
}
/*
0 - 100 intensity
*/
void Dimmer::setIntensity(int i){
	intensity = i;
	analogWrite(pin, map(intensity, 0, 100, 0, 255));
}
int Dimmer::getIntensity(){
	return intensity;
}



//DimmerClass Dimmer;

