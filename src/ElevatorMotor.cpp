/*
  ElevatorMotor.cpp - Library for Elevator Motor interaction of Robot Braman.
  Created by Vadim Pitenko.
*/

#include "Arduino.h"
#include "ElevatorMotor.h"

ElevatorMotor::ElevatorMotor(int pin1, int pin2, int pin3, int pin4, int optPin)
{
	_pins[0] = pin1;
	_pins[1] = pin2;
	_pins[2] = pin3;
	_pins[3] = pin4;
	_optPin = optPin;
	_delay = 1;
	_optPinAnalog = false;
}

void ElevatorMotor::init()
{
	for(int i=0; i<4; i++)
		pinMode(_pins[i], OUTPUT);

	pinMode(_optPin, INPUT);
}

void ElevatorMotor::setDelay(int delay)
{
	_delay = delay;
}

void ElevatorMotor::setOptPinToAnalog()
{
	_optPinAnalog = true;
}

bool ElevatorMotor::isOptClosed()
{
	if(_optPinAnalog)
		return analogRead(_optPin) <= 0;
	else
		return digitalRead(_optPin) <= 0;
}
	
bool ElevatorMotor::renull()
{
	if(isOptClosed())
		moveTo(1000, false);
  
	int tryCnt = 5000;
	while(tryCnt > 0) 
	{
		moveTo(8, true);
		if(isOptClosed()) 
		{
			moveTo(200, true);
			//Serial.println("SM Set to NULL");
			return true;
		}
		tryCnt--;
	}

	//Serial.println("FAILED SM Set to NULL");
	return false;
}
	
void ElevatorMotor::moveTo(int stepsCnt, bool forward)
{
	for(int i=0; i<stepsCnt; i++)
		move(forward);
}

void ElevatorMotor::moveTo(int stepsCnt)
{
	for(int i=0; i<stepsCnt; i++)
		move(true);
}

void ElevatorMotor::move(bool forward)
{
	if(forward)
		_step++;
	else
		_step--;

	updateValues();
}
	
void ElevatorMotor::updateValues()
{
	_takt = (8+_step%8)%8;
	int idx = (_takt%8)*4;

	for(int i=0; i<4; i++)
		digitalWrite(_pins[i], _steps[idx+i]);
	
	delay(_delay);
}