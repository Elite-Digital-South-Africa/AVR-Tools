#include "SPIHost.h"
#include <stdint.h>
#include <avr/io.h>

#define SCK PORTB5
#define MOSI PORTB3
#define SS PORTB2

void SPIMaster::InitSPI(){
	DDRB=(1<<SS)|(1<<MOSI)|(1<<SCK);
	PORTB=(1<<SS);
	SPCR=(1<<SPE)|(1<<MSTR);
}

uint8_t SPIMaster::tranceive(uint8_t data){
	SPDR=data;
	while (!(SPSR&(1<<SPIF)));
	return SPDR;
}

uint8_t SPIMaster::receive(){
	while (!(SPSR&(1<<SPIF)));
	return SPDR;
}

void SPIMaster::send(uint8_t data){
	SPDR=data;
	while (!(SPSR&(1<<SPIF)));
}

SPIMaster SPIHost;