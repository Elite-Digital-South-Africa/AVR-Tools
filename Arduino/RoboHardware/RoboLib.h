#ifndef RoboLib_h
#define RoboLib_h
#include <Arduino.h>

class RoboLib{
  public:
  RoboLib();
  void setDriveMotors(byte ,byte );
  void setWheelTrackers(byte,byte);
  void mainLooper();
  void init();
  boolean enableTracking;
  byte driveSpeed;
  byte ledPin;
  float proximityDistanceCM;
  float proximityDistanceIN;
  byte proximityTriggerPin;
  byte proximityEchoPin;
  boolean proximitySensorEnabled;
  byte motorPin1;
	byte motorPin2;
private:
	boolean clearStr;
	String commandData;
	byte trackerPin1;
	byte trackerPin2;
	int trackerValue1;
	int trackerValue2;
	/*int wheelAngle1;
	int wheelAngle2;*/
	void processData();
	void execCmd(String,String);
	float transmitEchoes();
	long delayTime;
};

#endif