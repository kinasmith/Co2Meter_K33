// CO2 Meter K‐series Example Interface
// by Andrew Robinson, CO2 Meter <co2meter.com>
// Talks via I2C to K33‐ELG/BLG Sensors for Host‐Initiated Data Collection 
// 4.1.2011

//Modified into Arduio Library by Kina Smith <kinasmith.com>
//06.09.2016



#ifndef Co2Meter_K33_H
#define Co2Meter_K33_H

#include "Arduino.h"


class Co2Meter_K33
{
public:
	Co2Meter_K33();
	~Co2Meter_K33();
	void wakeSensor();
	void initPoll();
	double readCo2();
	double readTemp();
	double readRh();
private:
	int co2Addr;

};

#endif