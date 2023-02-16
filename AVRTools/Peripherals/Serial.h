#ifndef SERIALD_H_
#define SERIALD_H_

#include <avr/io.h>
#include "../Core/Defines.h"

class SerialD{
	public:
	SerialD(uint32_t baudRate);
	void Write(unsigned char charToWrite);
	unsigned char Read();
	bool Available();
	private:
};

#if defined (__AVR_ATmega328PB__)

class SerialB{
	public:
	SerialB(uint32_t baudRate);
	void Write(unsigned char charToWrite);
	unsigned char Read();
	bool Available();
	private:
};

#endif


	
	//class SerialB{
		//public:
		//SerialB(uint32_t baudRate);
		//void Write(unsigned char charToWrite);
		//unsigned char Read();
		//bool Available();
		//private:
	//};

#endif