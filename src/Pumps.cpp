/*
  Pumps.cpp - Library for Pumps interaction of Robot Braman.
  Created by Vadim Pitenko.
*/

#include "Arduino.h"
#include "Pumps.h"

Pumps::Pumps(int pin1, int pin2, int pin3)
{
	_pins[0] = pin1;
	_pins[1] = pin2;
	_pins[2] = pin3;
	_workTime = 10;
}

void Pumps::init()
{
	for(int i=0; i<3; i++)
		pinMode(_pins[i], OUTPUT);
}

void Pumps::moveTo(int idx, int stepsCnt)
{
	moveTo(idx, stepsCnt, 0);
}
	
void Pumps::moveTo(int idx, int stepsCnt, int pwm)
{
	for(int i=0; i<stepsCnt; i++)
		move(idx, pwm);
}

void Pumps::move(int idx)
{
	move(idx, 0);
}

void Pumps::move(int idx, int pwm)
{
	switch(idx)
	{
		case 0: updateValues(0, 0, 1); break;
		case 1: updateValues(0, 1, 1); break;
		case 2: updateValues(1, 1, 1); break;
		default: updateValues(0, 0, 0); break;
	}
	delay(_workTime);
	updateValues(0, 0, 0);

	delay(pwm);
}

void Pumps::updateValues(int v1, int v2, int v3) {
  digitalWrite(_pins[0], v1);
  digitalWrite(_pins[1], v2);
  digitalWrite(_pins[2], v3);
}