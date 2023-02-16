#ifndef PWM_H_
#define PWM_H_

enum PWMMode{PhaseCorrect,FastPWM};
	
enum Timer0Prescalers{T0P_None,T0P_8,T0P_64,T0P_256,T0P_1024};
enum Timer2Prescalers{T2P_None,T2P_8,T2P_32,T2P_64,T2P_128,T2P_256,T2P_1024};
	
enum Timer0OutPins{PD6_OC0A,PD5_OC0B,PD6_0A_PD5_0B};
enum Timer2OutPins{PB3_OC2A,PD3_OC2B,PB3_2A_PD3_2B};

class Timer0PWMClass{
	public:
	void InitPWM(Timer0Prescalers prescaler,PWMMode mode,Timer0OutPins outPin);
	void SetDutyCycle(int dutyCycle,Timer0OutPins outPin);
};
extern Timer0PWMClass Timer0PWM;

class Timer2PWMClass{
	public:
	void InitPWM(Timer2Prescalers prescaler,PWMMode mode,Timer2OutPins outPin);
	void SetDutyCycle(int dutyCycle,Timer2OutPins outPin);
};
extern Timer2PWMClass Timer2PWM;

#endif