/*
  Pumps.h - Library for Pumps interaction of Robot Braman.
  Created by Vadim Pitenko.
*/
#ifndef Pumps_h
#define Pumps_h

#include "Arduino.h"

class Pumps
{
  public:
    Pumps(int pin1, int pin2, int pin3);
    void init();
    
	void moveTo(int idx, int stepsCnt, int pwm);
	void moveTo(int idx, int stepsCnt);
	
	void move(int idx, int pwm);
	void move(int idx);
	
  private:
    int _pins[3];
	int _workTime;
	
	void updateValues(int v1, int v2, int v3);
};

#endif