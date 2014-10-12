#pragma config(Sensor, S3,     IR,             sensorI2CCustom)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)

//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "functions\twoWheelMovement.c"
#include "drivers\hitechnic-sensormux.h"     //Drivers for IR Beacon
#include "drivers\hitechnic-irseeker-v2.h"
//#include "drivers\hitechnic-gyro.h"
#include "functions\Common.c"
#include "functions\MovementCommon.c"
#include "functions\turnFunction.c"

#define pointA 3
#define pointB 8
#define pointC 15
#define pointD 20
#define distanceA1 36.0
#define distanceA2 24.0
#define distanceB1 23.0
#define distanceB2 10.0
#define distanceC1 15.0
#define distanceC2 13.0
#define distanceD1 3.0
#define distanceD2 18.0
#define distanceD3 13.0

int getIRReading(tSensors ir_seeker)
{
	wait1Msec(1);                              // Wait 1 ms
	int ir = HTIRS2readACDir(ir_seeker);      // IR receiver -> ir variable
	wait1Msec(1);                              // Down time before recheck
	return ir;
}

float findIR(tSensors ir_seeker)
{
	int	ir_value = getIRReading(ir_seeker);
	repeatUntil(ir_value == 2)
	{
		backward(50);
		wait1Msec(1);
		ir_value = getIRReading(ir_seeker);
	}
	stopMotors();
	int encoderValue = (nMotorEncoder[leftFront] + nMotorEncoder[rightFront]) / 2;
	return calculateDist(encoderValue);
}


void strategyA()
{
	turn(90, dLeft);
	travelDistance(distanceA1);
	turn(90, dLeft);
	travelDistance(distanceA2);
}

void strategyB()
{
	turn(90, dLeft);
	travelDistance(distanceB1);
	turn(90, dRight);
	travelDistance(distanceB2);
}

void strategyC()
{
	turn(90, dLeft);
	travelDistance(distanceC1);
	turn(45, dRight);
	travelDistance(distanceC2);
}

void strategyD()
{
	travelDistance(distanceD1);
	turn(90, dLeft);
	travelDistance(distanceD2);
	turn(90, dLeft);
	travelDistance(distanceD3);
}

task main()
{
//	waitForStartOrButton();
	string text;
	eraseDisplay();
	float travelled = abs(findIR(IR));
	sprintf(text, "distance = %f", calculateDist(travelled));
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
	else(travelled <= pointD)
	{
		displayCenteredTextLine(2, "Strategy D");
		strategyD();
	}
}
