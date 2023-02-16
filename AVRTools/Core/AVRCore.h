#ifndef AVRCORE_H_
#define AVRCORE_H_

#include <avr/io.h>
#include "Defines.h"

class AVRCore{
	public:
	inline AVRCore();
	void Initialize();
	private:
};

extern AVRCore Core;

#endif