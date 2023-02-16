#define F_CPU 16000000
#include "UART.h"
#include <avr/io.h>
#include <string.h>
#include "String.h"

void UART::InitSerial(int baudRate){
	uint16_t BAUD_PRESCALE=(F_CPU/4/baudRate-1)/2;
	UBRR0H=(BAUD_PRESCALE>>8);
	UBRR0L=BAUD_PRESCALE;
	UCSR0C=(1<<UCSZ00)|(1<<UCSZ01);
	UCSR0B=(1<<TXEN0)|(1<<RXEN0);
	UCSR0A=(1<<U2X0);
}

void UART::sendloc(char mByte){
	while (!(UCSR0A&(1<<UDRE0)));
	UDR0=mByte;
}

void UART::Send(char* str){
	for (int i=0;i<(int)strlen(str);i++)
	{
		this->sendloc(str[i]);
	}
}

void UART::Send(String str){
	for (int i=0;i<(int)strlen(str.toCharArray());i++)
	{
		this->sendloc(str.toCharArray()[i]);
	}
}

void UART::SendChar(char str){
	this->sendloc(str);
}

char UART::Read(){
	while (!(UCSR0A&(1<<RXC0)));
	return UDR0;
}

bool UART::available(){
	if(UCSR0A&(1<<RXC0)){
		return true;
		}else{
		return false;
	}
}

UART RawUART;