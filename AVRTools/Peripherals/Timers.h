#ifndef TIMERS_H_
#define TIMERS_H_

#include <avr/io.h>
#include "../Core/Defines.h"

class Timer1PWM{
	public:
	Timer1PWM();
	void SetDutyPB1(uint8_t dutyCycle);
	void SetDutyPB2(uint8_t dutyCycle);
	private:
};

extern unsigned long microSeconds;
extern unsigned long milliSeconds();

class Timer0Counter{
	public:
	inline Timer0Counter();
	void Initialize();
	private:
};

extern Timer0Counter Timer0;

#endif