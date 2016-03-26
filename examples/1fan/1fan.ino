#include "Dimmer.h"

Dimmer fan(6);

void setup()
{
	fan.begin();
}

void loop()
{
	fan.setIntensity(85);
	int fanIntensity = fan.getIntensity();
}
