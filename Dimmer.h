// Dimmer.h

#include "Relay.h"

#ifndef _DIMMER_h
#define _DIMMER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "Arduino.h"
#else
	#include "WProgram.h"
#endif

class Dimmer
{
 protected:
	 int pin;
	 int intensity;
 public:
	 Dimmer();
	 Dimmer(int p);
	 void begin();
	 void setPin(int p);
	 int getPin();
	 void setIntensity(int i);
	 int getIntensity();

};

//extern DimmerClass Dimmer;

#endif

