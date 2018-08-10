/*
  BaseMotor.cpp - Library for Base Motor interaction of Robot Braman.
  Created by Vadim Pitenko.
*/

#include "Arduino.h"
#include "BaseMotor.h"

BaseMotor::BaseMotor(int pin1, int pin2, int pin3, int pin4, int optPin)
{
	_pins[0] = pin1;
	_pins[1] = pin2;
	_pins[2] = pin3;
	_pins[3] = pin4;
	_optPin = optPin;
	_delay = 1;
	_optPinAnalog = false;
}

void BaseMotor::init()
{
	for(int i=0; i<4; i++)
		pinMode(_pins[i], OUTPUT);

	pinMode(_optPin, INPUT);
}

void BaseMotor::setDelay(int delay)
{
	_delay = delay;
}

void BaseMotor::setOptPinToAnalog()
{
	_optPinAnalog = true;
}

bool BaseMotor::isOptClosed()
{
	Serial.println("Method BaseMotor.isOptClosed() is not implemented");
	return false;
}
	
bool BaseMotor::renull()
{
	Serial.println("Method BaseMotor.renull() is not implemented");
	return false;
}
	
void BaseMotor::moveTo(int stepsCnt, bool forward)
{
	for(int i=0; i<stepsCnt; i++)
		move(forward);
}

void BaseMotor::moveTo(int stepsCnt)
{
	for(int i=0; i<stepsCnt; i++)
		move(true);
}

void BaseMotor::move(bool forward)
{
	if(forward)
		_step++;
	else
		_step--;

	updateValues();
}
	
void BaseMotor::updateValues()
{
	_takt = (8+_step%8)%8;
	int idx = (_takt%8)*4;

	for(int i=0; i<4; i++) {
		//Serial.print(_steps[idx+i]);
		//Serial.print(" ");
		digitalWrite(_pins[i], _steps[idx+i]);
	}
	//Serial.println(" ");
	
	delay(_delay);
}