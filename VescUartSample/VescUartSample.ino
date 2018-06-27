/*
 Name:		VescUartSample.ino
 Created:	9/26/2015 10:12:38 PM
 Author:	AC
*/

// the setup function runs once when you press reset or power the board
// To use VescUartControl stand alone you need to define a config.h file, that should contain the Serial or you have to comment the line
// #include Config.h out in VescUart.h

//Include libraries copied from VESC

#define DEBUG 
#include "Config.h"
#include "VescUart.h"
#include "datatypes.h"


unsigned long count;

void setup() {
	
	//Setup UART port
	SetSerialPort(&SERIALIO);
	SERIALIO.begin(115200);
#ifdef DEBUG
	//SEtup debug port
	SetDebugSerialPort(&DEBUGSERIAL);
	DEBUGSERIAL.begin(115200);
	#endif
	
}

struct bldcMeasure measuredVal;
	
// the loop function runs over and over again until power down or reset
void loop() {

	delay(2000);  //delay this loop, for demonstration only, this can be much quicker
	if (VescUartGetValue(measuredVal)) {
		DEBUGSERIAL.print("Loop: "); DEBUGSERIAL.println(count++);
		SerialPrint(measuredVal);
	}
	else
	{
		Serial.println("Failed to get data!");
	}
  float dutycyletoset = 0.0515; // a value between 0 and 1 as float, will select duty cyle setting for vesc with this value. i.e 0.0515 is 5.15% dutycycle
  VescUartSetDuty(dutycyletoset); // initiate a transfer to vesc and set the duty cycle to the above value, you can confirm this with the VescTool
	
}





