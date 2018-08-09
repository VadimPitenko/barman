/*
  BaseMotor.h - Library for Base Motor interaction of Robot Braman.
  Created by Vadim Pitenko.
*/
#ifndef BaseMotor_h
#define BaseMotor_h

#include "Arduino.h"

class BaseMotor
{
  public:
    BaseMotor(int pin1, int pin2, int pin3, int pin4, int optPin);
    void init();
    bool renull();
	void setDelay(int delay);
	void setOptPinToAnalog();
	
	void moveTo(int stepsCnt, bool forward);
	void moveTo(int stepsCnt);
	void move(bool forward);
	
  private:
    int _pins[4];
	int _delay;
	int _step;
	int _takt;
	
	void updateValues();
	
  protected:
	int _steps[32];
	int _optPin;
	bool _optPinAnalog;
	
	bool isOptClosed();
};

#endif