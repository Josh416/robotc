#pragma config(Sensor, S3,     IR,             sensorI2CCustom)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//#pragma config(Sensor, S3,     IR,             sensorI2CCustom)
#include "twoWheelMovement.c"
#include "hitechnic-sensormux.h"     //Drivers for IR Beacon
#include "IRsensor.c"

void faceIR(tSensors ir_seeker)
{
	int	ir_value = getIRReading(ir_seeker);
	do
	{
		if(ir_value < 2)
		{
			leftTurn(50);
		}
		else if(ir_value > 2)
		{
			rightTurn(50);
		}
		wait1Msec(1);
		ir_value = getIRReading(ir_seeker);
	}
	while(ir_value != 2);
}

task main()
{
	faceIR(IR);
	stopMotors();
}
