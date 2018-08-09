/*
  TableMotor.cpp - Library for Table Motor interaction of Robot Braman.
  Created by Vadim Pitenko.
*/

#include "Arduino.h"
#include "TableMotor.h"

TableMotor::TableMotor(int pin1, int pin2, int pin3, int pin4, int optPin)
{
	_pins[0] = pin1;
	_pins[1] = pin2;
	_pins[2] = pin3;
	_pins[3] = pin4;
	_optPin = optPin;
	_delay = 5;
	_optPinAnalog = false;
}

void TableMotor::init()
{
	for(int i=0; i<4; i++)
		pinMode(_pins[i], OUTPUT);

	pinMode(_optPin, INPUT);
}

void TableMotor::setDelay(int delay)
{
	_delay = delay;
}

void TableMotor::setOptPinToAnalog()
{
	_optPinAnalog = true;
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
	
void TableMotor::moveTo(int stepsCnt, bool forward)
{
	for(int i=0; i<stespCnt; i++)
		move(forward);
}

void TableMotor::moveTo(int stepsCnt)
{
	for(int i=0; i<stespCnt; i++)
		move(true);
}

void TableMotor::move(bool forward)
{
	if(forward)
		_step++;
	else
		_step--;

	updateValues();
}
	
void TableMotor::updateValues()
{
	_takt = (8+_step%8)%8;
	int idx = (_takt%8)*4;

	for(int i=0; i<4; i++)
		digitalWrite(_pins[i], _steps[idx+i]);
	
	delay(_delay);
}