/*
  TableMotor.h - Library for Table Motor interaction of Robot Braman.
  Created by Vadim Pitenko.
*/
#ifndef TableMotor_h
#define TableMotor_h

#include "Arduino.h"

const int _steps[32] = {
    1, 0, 0, 0,
    1, 0, 1, 0,
    0, 0, 1, 0,
    0, 1, 1, 0,
    0, 1, 0, 0,
    0, 1, 0, 1,
    0, 0, 0, 1,
    1, 0, 0, 1
  };

class TableMotor
{
  public:
    TableMotor(int pin1, int pin2, int pin3, int pin4, int optPin);
    void init();
    bool renull();
	void setDelay(int delay);
	void setOptPinToAnalog();
	
	void moveTo(int stepsCnt, bool forward);
	void moveTo(int stepsCnt);
	void move(bool forward);
	
  private:
    int _pins[4];
	int _optPin;
	int _delay;
	int _step;
	int _takt;
	
	bool _optPinAnalog;
	
	void updateValues();
	bool isOptClosed();
};

#endif