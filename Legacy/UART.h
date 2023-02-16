#ifndef UART_H_
#define UART_H_
#include "String.h"

class UART{
	public:
	void InitSerial(int baudRate);
	void Send(char* str);
	void Send(String str);
	void SendChar(char str);
	char Read();
	bool available();
	private:
	void sendloc(char mByte);
};

extern UART RawUART;

#endif