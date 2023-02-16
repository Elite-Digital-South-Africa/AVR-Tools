#include <avr/io.h>
#include <avr/interrupt.h>
#include "../Core/Defines.h"
#include "Serial.h"

#if defined (__AVR_ATmega328P__)

ISR(USART_RX_vect){
	
}

ISR(USART_TX_vect){
	
}

ISR(USART_UDRE_vect){
	
}

#elif  defined (__AVR_ATmega328PB__)

ISR(USART0_RX_vect){
	
}

ISR(USART0_TX_vect){
	
}

ISR(USART0_UDRE_vect){
	
}

ISR(USART1_RX_vect){
	
}

ISR(USART1_TX_vect){
	
}

ISR(USART1_UDRE_vect){
	
}

SerialB::SerialB(uint32_t baudRate){
#define UBRR1Val ((F_CPU / (8 * baudRate)) - 1)
UBRR1H = (UBRR1Val >> 8) & 0x0F;
UBRR1L = (UBRR1Val >> 0) & 0xFF;
UCSR1C |= (0<<UMSEL11) | (0<<UMSEL10) // Async mode
| (0<<UPM11) | (0<<UPM10)  // Parity disable
| (0<<USBS1)  // 1 Stop bit
| (1<<UCSZ11) | (1<<UCSZ10)  // 8 bit chars
| (0<<UCPOL1); // Clk polarity, 0 for async mode
UCSR1A |= (1<<U2X1); // Double speed
UCSR1B |= (1<<RXEN1) | (1<<TXEN1) | (1<<RXCIE1) | (1<<TXCIE1) | (1<<UDRIE1) // TX and RX enable, and interrupts //
| (0<<UCSZ12);
}

void SerialB::Write(unsigned char charToWrite){
while (!(UCSR1A & (1<<UDRE1)));
UDR1 = charToWrite;
}

unsigned char SerialB::Read(){
return UDR1;
}

bool SerialB::Available(){
return (UCSR1A & (1<<RXC1));
}

#endif

SerialD::SerialD(uint32_t baudRate){
	#define UBRR0Val ((F_CPU / (8 * baudRate)) - 1)
	UBRR0H = (UBRR0Val >> 8) & 0x0F;
	UBRR0L = (UBRR0Val >> 0) & 0xFF;
	UCSR0C |= (0<<UMSEL01) | (0<<UMSEL00) // Async mode
	| (0<<UPM01) | (0<<UPM00)  // Parity disable
	| (0<<USBS0)  // 1 Stop bit
	| (1<<UCSZ01) | (1<<UCSZ00)  // 8 bit chars
	| (0<<UCPOL0); // Clk polarity, 0 for async mode
	UCSR0A |= (1<<U2X0); // Double speed
	UCSR0B |= (1<<RXEN0) | (1<<TXEN0) | (1<<RXCIE0) | (1<<TXCIE0) | (1<<UDRIE0) // TX and RX enable, and interrupts //
	| (0<<UCSZ02);
}

void SerialD::Write(unsigned char charToWrite){
	while (!(UCSR0A & (1<<UDRE0)));
	UDR0 = charToWrite;
}

unsigned char SerialD::Read(){
	return UDR0;
}

bool SerialD::Available(){
	return (UCSR0A & (1<<RXC0));
}

