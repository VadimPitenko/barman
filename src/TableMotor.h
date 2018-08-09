/*
  TableMotor.h - Library for Table Motor interaction of Robot Braman.
  Created by Vadim Pitenko.
*/
#ifndef TableMotor_h
#define TableMotor_h

#include "Arduino.h"
#include "BaseMotor.h"

class TableMotor : public BaseMotor
{
  public:
    TableMotor(int pin1, int pin2, int pin3, int pin4, int optPin);
	bool renull();
	
  private:
	bool isOptClosed();
};

#endif