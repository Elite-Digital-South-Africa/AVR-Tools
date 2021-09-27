#ifndef SPIHOST_H_
#define SPIHOST_H_

#include <stdint.h>

class SPIMaster{
	public:
	void InitSPI();
	uint8_t tranceive(uint8_t data);
	uint8_t receive();
	void send(uint8_t data);
};

extern SPIMaster SPIHost;

#endif