#include "Dimmer.h"

Dimmer fan1(3); //pwn pin connected to arduino
Dimmer fan2(5);
Dimmer fan3(6);

void setup()
{
	fan1.begin();
	fan2.begin();
	fan3.begin();
}

void loop()
{
	fan1.setIntensity(85); //sets the pwn intensity in %(0 - 100)
	fan2.setIntensity(50);
	fan3.setIntensity(20);
	
}
