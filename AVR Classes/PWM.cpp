#include "PWM.h"
#include <avr/io.h>

void Timer0PWMClass::InitPWM(Timer0Prescalers prescaler,PWMMode mode,Timer0OutPins outPin){
	
	switch(outPin){
		case PD6_OC0A:
		TCCR0A ^= (1<<COM0A1);
		break;
		case PD5_OC0B:
		TCCR0A ^= (1<<COM0B1);
		break;
		case PD6_0A_PD5_0B:
		TCCR0A ^= (1<<COM0A1)|(1<<COM0B1);
		break;
	}
	
	switch(mode){
		case PhaseCorrect:
		TCCR0A ^= (1<<WGM00)|(0<<WGM01);
		break;
		case FastPWM:
		TCCR0A ^= (1<<WGM00)|(1<<WGM01);
		break;
	}
	
	switch (prescaler)
	{
		case T0P_None:
		TCCR0B^=(0<<CS02)|(0<<CS01)|(1<<CS00);
		break;
		case T0P_8:
		TCCR0B^=(0<<CS02)|(1<<CS01)|(0<<CS00);
		break;
		case T0P_64:
		TCCR0B^=(0<<CS02)|(1<<CS01)|(1<<CS00);
		break;
		case T0P_256:
		TCCR0B^=(1<<CS02)|(0<<CS01)|(0<<CS00);
		break;
		case T0P_1024:
		TCCR0B^=(1<<CS02)|(0<<CS01)|(1<<CS00);
		break;
	}
	
	switch(outPin){
		case PD6_OC0A:
		DDRD^=(1<<PORTD6);
		OCR0A=0;
		break;
		case PD5_OC0B:
		DDRD^=(1<<PORTD5);
		OCR0B=0;
		break;
		case PD6_0A_PD5_0B:
		DDRD^=(1<<PORTD6);
		DDRD^=(1<<PORTD5);
		OCR0A=0;
		OCR0B=0;
		break;
	}
	
}

void Timer0PWMClass::SetDutyCycle(int dutyCycle,Timer0OutPins outPin){
	
	switch(outPin){
		case PD6_OC0A:
		OCR0A=dutyCycle;
		break;
		case PD5_OC0B:
		OCR0B=dutyCycle;
		break;
		case PD6_0A_PD5_0B:
		OCR0A=dutyCycle;
		OCR0B=dutyCycle;
		break;
	}
	
}

Timer0PWMClass Timer0PWM;

void Timer2PWMClass::InitPWM(Timer2Prescalers prescaler,PWMMode mode,Timer2OutPins outPin){
	
	switch(outPin){
		case PB3_OC2A:
		TCCR2A ^= (1<<COM2A1);
		break;
		case PD3_OC2B:
		TCCR2A ^= (1<<COM2B1);
		break;
		case PB3_2A_PD3_2B:
		TCCR2A ^= (1<<COM2A1)|(1<<COM2B1);
		break;
	}
	
	switch(mode){
		case PhaseCorrect:
		TCCR2A ^= (1<<WGM20)|(0<<WGM21);
		break;
		case FastPWM:
		TCCR2A ^= (1<<WGM20)|(1<<WGM21);
		break;
	}
	
	switch (prescaler)
	{
		case T2P_None:
		TCCR2B^=(0<<CS22)|(0<<CS21)|(1<<CS20);
		break;
		case T2P_8:
		TCCR2B^=(0<<CS22)|(1<<CS21)|(0<<CS20);
		break;
		case T2P_32:
		TCCR2B^=(0<<CS22)|(1<<CS21)|(1<<CS20);
		break;
		case T2P_64:
		TCCR2B^=(1<<CS22)|(0<<CS21)|(0<<CS20);
		break;
		case T2P_128:
		TCCR2B^=(1<<CS22)|(0<<CS21)|(1<<CS20);
		break;
		case T2P_256:
		TCCR2B^=(1<<CS22)|(1<<CS21)|(0<<CS20);
		break;
		case T2P_1024:
		TCCR2B^=(1<<CS22)|(1<<CS21)|(1<<CS20);
		break;
	}
	
	switch(outPin){
		case PB3_OC2A:
		DDRB^=(1<<PORTB3);
		OCR2A=0;
		break;
		case PD3_OC2B:
		DDRD^=(1<<PORTD3);
		OCR2B=0;
		break;
		case PB3_2A_PD3_2B:
		DDRB^=(1<<PORTB3);
		DDRD^=(1<<PORTD3);
		OCR2A=0;
		OCR2B=0;
		break;
	}
	
}

void Timer2PWMClass::SetDutyCycle(int dutyCycle,Timer2OutPins outPin){
	
	switch(outPin){
		case PB3_OC2A:
		OCR2A=dutyCycle;
		break;
		case PD3_OC2B:
		OCR2B=dutyCycle;
		break;
		case PB3_2A_PD3_2B:
		OCR2A=dutyCycle;
		OCR2B=dutyCycle;
		break;
	}
	
}

Timer2PWMClass Timer2PWM;