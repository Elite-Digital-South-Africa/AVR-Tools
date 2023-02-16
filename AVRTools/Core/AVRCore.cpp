#include <avr/io.h>
#include <avr/interrupt.h>
#include "Defines.h"
#include "LightningCore.h"
#include "../Peripherals/Timers.h"

AVRCore::AVRCore(){
	
}

void AVRCore::Initialize(){
	Timer0.Initialize();
	sei();
}

AVRCore Core;