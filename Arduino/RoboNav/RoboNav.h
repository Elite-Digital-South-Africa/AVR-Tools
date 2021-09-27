#ifndef RoboNav_h
#define RoboNav_h
#include <Arduino.h>
#include <RoboLib.h>


class RoboNav{
public:
	RoboNav();
	void setDirection(String);
	void drive();
	void avoidObstacles();
	void setLibClass(RoboLib);
private:
	RoboLib roboLib;
	long timer;
	byte wheelSpeed1;
	byte wheelSpeed2;
};

#endif