#include <RoboNav.h>

RoboNav::RoboNav(){
	RoboNav::wheelSpeed1=0;
	RoboNav::wheelSpeed2=0;
	RoboNav::timer=0;
}

void RoboNav::setDirection(String direction){
	
	if(direction=="left"){
	RoboNav::wheelSpeed1=RoboNav::roboLib.driveSpeed/2;
	//RoboNav::wheelSpeed2=RoboNav::roboLib.driveSpeed/100*120;
	}else if(direction=="right"){
	//RoboNav::wheelSpeed1=RoboNav::roboLib.driveSpeed/100*120;
	RoboNav::wheelSpeed2=RoboNav::roboLib.driveSpeed/2;
	}else if(direction=="forward"){
	RoboNav::wheelSpeed1=RoboNav::roboLib.driveSpeed;
	RoboNav::wheelSpeed2=RoboNav::roboLib.driveSpeed;
	}

}

void RoboNav::drive(){
	if(RoboNav::wheelSpeed1==0||RoboNav::wheelSpeed2==0){
		//Serial.println("speed=0");
	RoboNav::wheelSpeed1=RoboNav::roboLib.driveSpeed;
	RoboNav::wheelSpeed2=RoboNav::roboLib.driveSpeed;
	}
	//Serial.println(RoboNav::roboLib.motorPin1);
	analogWrite(RoboNav::roboLib.motorPin1,RoboNav::wheelSpeed1);
analogWrite(RoboNav::roboLib.motorPin2,RoboNav::wheelSpeed2);
}

void RoboNav::avoidObstacles(){
	if(millis()-RoboNav::timer>=500){
	if(RoboNav::roboLib.proximityDistanceCM<=35.0f){
		String directions[2]={"left","right"};
	byte direction=random(2);
	RoboNav::setDirection(directions[direction]);
	}else{
	RoboNav::setDirection("forward");
	}
	RoboNav::timer=millis();
	}
	
	
}

void RoboNav::setLibClass(RoboLib mRoboLib){
	RoboNav::roboLib=mRoboLib;
	//Serial.println(RoboNav::roboLib.motorPin1);
}