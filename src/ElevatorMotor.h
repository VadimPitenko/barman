/*
  ElevatorMotor.h - Library for Elevator Motor interaction of Robot Braman.
  Created by Vadim Pitenko.
*/
#ifndef ElevatorMotor_h
#define ElevatorMotor_h

#include "Arduino.h"
#include "BaseMotor.h"

class ElevatorMotor : public BaseMotor
{
  public:
    ElevatorMotor(int pin1, int pin2, int pin3, int pin4, int optPin);
    bool renull();
	
  private:
    bool isOptClosed();
};

#endif