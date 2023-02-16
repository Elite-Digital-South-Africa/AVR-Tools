#include <avr/io.h>
#include <avr/interrupt.h>
#include "../Core/Defines.h"
#include "Timers.h"

ISR(TIMER1_OVF_vect){
	
}

ISR(TIMER1_COMPA_vect){
	
}

ISR(TIMER1_COMPB_vect){
	
}

Timer1PWM::Timer1PWM(){
	TCCR1A |= (1<<COM1A1) | (1<<COM1B1) |(0<<COM1A0) | (0<<COM1B0) | (0<<WGM11) | (1<<WGM10);
	TCCR1B |= (0<<WGM13) | (1<<WGM12) |(0<<CS12) | (0<<CS11) | (1<<CS10);
	OCR1AL = 0;
	OCR1BL = 0;
	TIMSK1 |= (1<<OCIE1B) | (1<<OCIE1A) | (1<<TOIE1);
	DDRB |= (1<<PINB1) | (1<<PINB2);
}

void Timer1PWM::SetDutyPB1(uint8_t dutyCycle){
	OCR1AL = dutyCycle;
}

void Timer1PWM::SetDutyPB2(uint8_t dutyCycle){
	OCR1BL = dutyCycle;
}

unsigned long microSeconds = 0;
unsigned long milliSeconds(){
	return microSeconds / 1000;
}

ISR(TIMER0_COMPA_vect){
	microSeconds+=10;
}

Timer0Counter::Timer0Counter(){
	
}

void Timer0Counter::Initialize(){
	TCCR0A = (0<<COM0A1) | (0<<COM0A0) | (1<<WGM01) | (0<<WGM00);
	TCCR0B = (0<<WGM02) |(0<<CS02) | (0<<CS01) | (1<<CS00);
	OCR0A = 159;
	TIMSK0 = (1<<OCIE0A);
}

Timer0Counter Timer0;