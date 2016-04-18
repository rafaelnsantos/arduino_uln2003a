#include "Dimmer.h"

Dimmer fan(6); //pwn pin connected to arduino

void setup()
{
	fan.begin();
}

void loop()
{
	fan.setIntensity(85); //sets the pwn intensity in %(0 - 100)
	
	int fanIntensity = fan.getIntensity(); //returns the intensity in %
}
