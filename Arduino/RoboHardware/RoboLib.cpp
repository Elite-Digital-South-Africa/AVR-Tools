#include <RoboLib.h>
//#include <HardwareSerial.h>

RoboLib::RoboLib(){
Serial.begin(9600);
RoboLib::enableTracking=false;
RoboLib::motorPin1=NULL;
RoboLib::motorPin2=NULL;
RoboLib::trackerPin1=NULL;
RoboLib::trackerPin2=NULL;
RoboLib::trackerValue1=NULL;
RoboLib::trackerValue2=NULL;
//RoboLib::wheelAngle1=NULL;
//RoboLib::wheelAngle2=NULL;
RoboLib::driveSpeed=255;
RoboLib::clearStr=false;
RoboLib::commandData="";
RoboLib::ledPin=NULL;
RoboLib::proximityDistanceCM=NULL;
	RoboLib::proximityDistanceIN=NULL;
	RoboLib::proximityTriggerPin=NULL;
	RoboLib::proximityEchoPin=NULL;
	RoboLib::proximitySensorEnabled=false;
	RoboLib::delayTime=NULL;
}

void RoboLib::setDriveMotors(byte mPin1,byte mPin2){
	RoboLib::motorPin1=mPin1;
	RoboLib::motorPin2=mPin2;
}

void RoboLib::setWheelTrackers(byte mSens1,byte mSens2){
	RoboLib::trackerPin1=mSens1;
	RoboLib::trackerPin2=mSens2;
}

void RoboLib::init(){
	
	if(RoboLib::motorPin1!=NULL){
	pinMode(RoboLib::motorPin1,OUTPUT);
	//Serial.println("not null");
	}
	if(RoboLib::motorPin2!=NULL){
	pinMode(RoboLib::motorPin2,OUTPUT);
	//Serial.println("not null");
	}
	if(RoboLib::ledPin!=NULL){
	pinMode(RoboLib::ledPin,OUTPUT);
	}
	if(RoboLib::proximityTriggerPin!=NULL){
	pinMode(RoboLib::proximityTriggerPin,OUTPUT);
	}
	if(RoboLib::proximityEchoPin!=NULL){
	pinMode(RoboLib::proximityEchoPin,INPUT);
	}
}

void RoboLib::mainLooper(){
	if(RoboLib::enableTracking){
		if(RoboLib::trackerPin1!=NULL){
		RoboLib::trackerValue1=analogRead(RoboLib::trackerPin1);
		}
		if(RoboLib::trackerPin2!=NULL){
		RoboLib::trackerValue2=analogRead(RoboLib::trackerPin2);
		}
	}

	if(Serial.available()>0){
    char val=Serial.read();
    if(val!=';'){
    RoboLib::commandData+=val;
    }else{
    RoboLib::clearStr=true;
    }
  }
if(RoboLib::clearStr){
RoboLib::processData();
RoboLib::commandData="";
RoboLib::clearStr=false;
}
if(RoboLib::proximitySensorEnabled){
	if(millis()-RoboLib::delayTime>249){
	float duration=	RoboLib::transmitEchoes();

RoboLib::proximityDistanceCM=duration/58.2f;
Serial.println(RoboLib::proximityDistanceCM);
RoboLib::proximityDistanceIN=duration/74/2;
		RoboLib::delayTime=millis();
	}

}

}

void RoboLib::processData(){
	int i=RoboLib::commandData.indexOf("=");
if(i!=-1){
String cmd=RoboLib::commandData.substring(0,i);
String value=RoboLib::commandData.substring(i+1,RoboLib::commandData.length());
RoboLib::execCmd(cmd,value);
}else{
Serial.println("Command syntax invalid.");
}

}

void RoboLib::execCmd(String cmd,String value){
if(cmd=="led"){
if(value=="on"){
digitalWrite(RoboLib::ledPin,HIGH);
Serial.println("LED turned on.");
}else if(value=="off"){
digitalWrite(RoboLib::ledPin,LOW);
Serial.println("LED turned off.");
}
}else if(cmd=="speed"){
	int mSpeed=atoi(value.c_str());
	Serial.println(mSpeed);
	if( mSpeed >-1 && mSpeed <= 255){
	RoboLib::driveSpeed=mSpeed;
	}else{
	Serial.println("Invalid speed value, please enter a number between 0 and 255.");
	}

}else if(cmd=="state"){
	if(value=="idle"){
	//RoboLib::mState=idle;
	}else if(value=="moving"){
	//RoboLib::mState=moving;
	}
}else{
Serial.println("Unrecognised Command.");
}
}

float RoboLib::transmitEchoes(){
digitalWrite(RoboLib::proximityTriggerPin,LOW);
delayMicroseconds(2);
digitalWrite(RoboLib::proximityTriggerPin,HIGH);
delayMicroseconds(10);
digitalWrite(RoboLib::proximityTriggerPin,LOW);
return pulseIn(RoboLib::proximityEchoPin,HIGH);
}
