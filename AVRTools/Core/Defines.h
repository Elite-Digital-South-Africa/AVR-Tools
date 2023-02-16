#ifndef DEFINES_H_
#define DEFINES_H_

#include <avr/io.h>

#if defined (Lightning3V)

#define F_CPU 9216000L

#else

#define F_CPU 16000000L

#endif

//int pinToBitByte(int pinNum){
	//switch (pinNum)
	//{
		//case 0:
			//return (PINB5 & PORTB);
		//break;
		//case 1:
			//return (PINB5 & PORTB);
		//break;
		//case 2:
			//return (PINB5 & PORTB);
		//break;
		//case 3:
			//return (PINB5 & PORTB);
		//break;
		//case 4:
			//return (PINB5 & PORTB);
		//break;
		//case 5:
			//return (PINB5 & PORTB);
		//break;
		//case 6:
			//return (PINB5 & PORTB);
		//break;
		//case 7:
			//return (PINB5 & PORTB);
		//break;
		//case 8:
			//return (PINB5 & PORTB);
		//break;
		//case 9:
			//return (PINB5 & PORTB);
		//break;
		//case 10:
			//return (PINB5 & PORTB);
		//break;
		//case 11:
			//return (PINB5 & PORTB);
		//break;
		//case 12:
			//return (PINB5 & PORTB);
		//break;
		//case 13:
			//return (PINB5 & PORTB);
		//break;
		//default:
		//return (PINB5 & PORTB);
		//break;
	//}
//}

#endif