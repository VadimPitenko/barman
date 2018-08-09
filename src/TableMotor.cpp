/*
  TableMotor.cpp - Library for Table Motor interaction of Robot Braman.
  Created by Vadim Pitenko.
*/

#include "Arduino.h"
#include "TableMotor.h"

TableMotor::TableMotor(int pin1, int pin2, int pin3, int pin4, int optPin) : BaseMotor(pin1, pin2, pin3, pin4, optPin)
{
	const int _TMsteps[32] = {
		1, 0, 0, 0,
		1, 0, 1, 0,
		0, 0, 1, 0,
		0, 1, 1, 0,
		0, 1, 0, 0,
		0, 1, 0, 1,
		0, 0, 0, 1,
		1, 0, 0, 1
	};
	
	for(int i=0; i<32; i++)
		_steps[i] = _TMsteps[i];
}

bool TableMotor::isOptClosed()
{
	if(_optPinAnalog)
		return analogRead(_optPin) > 300;
	else
		return digitalRead(_optPin) > 0;
}

bool TableMotor::renull()
{
	if(isOptClosed())
		moveTo(100, false);
  
	int tryCnt = 10000;
	while(tryCnt > 0) 
	{
		move(true);
		if(isOptClosed()) 
		{
			moveTo(90, true);
			//Serial.println("Set to NULL");
			return true;
		}
		tryCnt--;
	}

	//Serial.println("FAILED Set to NULL");
	return false;
}

