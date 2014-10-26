#pragma config(Sensor, S3,     HTIRS2,             sensorI2CCustom)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
#include "rpgCommon.c"
#include "IRsensor.c"
#include "twoWheelMovement.c"
#include "hitechnic-sensormux.h"     //Drivers for IR Beacon
#include "gyroSensor.c"
#include "gyroMovement.c"
#include "MovementCommon.c"
//#include "turnFunction.c"

#define pointA 10
#define pointB 44
#define pointC 60
#define pointD 10000
#define distanceA1 36.0
#define distanceA2 24.0
#define distanceD1 55.0
#define distanceD2 55.0
#define distanceC1 100.0
#define distanceB1 20.0
#define distanceB2 18.0
#define distanceB3 13.0



float findIR(tSensors ir_seeker)
{
	resetEncoders();
	int	ir_value = getIRReading(ir_seeker);
	backward(50);
	repeatUntil((ir_value == 2)||(abs(nMotorEncoder(leftFront))> 10000))
	{
		wait1Msec(1);
		ir_value = getIRReading(ir_seeker);
	}
	stopMotors();
	string text;

	int encoderValue = (abs(nMotorEncoder[leftFront]) + abs(nMotorEncoder[rightFront])) / 2;
	return calculateDist(encoderValue);
}

void strategyA()//use if in possistion 1
{
	leftTurn(50);
	gyroTurn(90);
	travelDistance(distanceA1);
	leftTurn(50);
	gyroTurn(90);
	travelDistance(distanceA2);
}

void strategyD()//use if in possistion 1
{
	leftTurn(50);
	gyroTurn(90);
	travelDistance(distanceD1);
	leftTurn(50);
	gyroTurn(90);
	travelDistance(distanceD2);
}

void strategyC()//use if in possistion 2
{
	leftTurn(50);
	gyroTurn(35);
	forward(100);
	wait1Msec(100000);
	travelDistance(distanceC1);
}

void strategyB()//use if in possistion 3
{
	travelDistance(distanceB1);
	leftTurn(50);
	gyroTurn(90);
	travelDistance(distanceB2);
	leftTurn(50);
	gyroTurn(90);
	travelDistance(distanceB3);
}

task main()
{
	waitForStartOrButton();
	string text;
	eraseDisplay();
	float travelled = abs(findIR(HTIRS2));
	sprintf(text, "left = %i", nMotorEncoder[leftFront]);
	displayCenteredTextLine(4, text);
	sprintf(text, "right = %i", nMotorEncoder[rightFront]);
	displayCenteredTextLine(5, text);

	sprintf(text, "distance = %f", travelled);
	displayCenteredTextLine(1, text);

	if(travelled <= pointA)
	{
		displayCenteredTextLine(2, "Strategy A");
		strategyA();
	}
	else if(travelled <= pointB)
	{
		displayCenteredTextLine(2, "Strategy B");
		strategyB();
	}

	else if(travelled <= pointC)
	{
		displayCenteredTextLine(2, "Strategy C");
		strategyC();
	}
	else if(travelled <= pointD)
	{
		displayCenteredTextLine(2, "Strategy D");
		strategyD();
	}
}
