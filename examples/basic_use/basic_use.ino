#include <Wire.h>
#include "Co2Meter_K33.h"

Co2Meter_K33 k33;

//In this example we will do a basic read of the CO2 value and checksum verification. 
//For more advanced applications please see the I2C Comm guide.

void setup() {
	Wire.begin();
	Serial.begin(9600);
	Serial.println("What a wonderful day, to read atmospheric CO2 concentrations!");
}

void loop() {
	// We keep the sample period >25s or so, else the sensor will start ignoring sample requests. 
	k33.initPoll();
	delay(16000); //wait for sensor to warm up
	double tempValue = k33.readTemp();
	delay(20); 
	double rhValue = k33.readRh();
	delay(20);
	double co2Value = k33.readCo2();
	if (co2Value >= 0) {
		Serial.print("CO2: ");
		Serial.print(co2Value);
		Serial.print("ppm Temp: ");
		Serial.print(tempValue);
		Serial.print("C Rh: ");
		Serial.print(rhValue);
		Serial.println("%");
	}
	else {
		Serial.println("Checksum failed / Communication failure");
		delay(9000);
	}
}