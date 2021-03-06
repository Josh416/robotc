#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     gyro,           sensorSONAR)
#pragma config(Sensor, S4,     HTSMUX,         sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_1,     rightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_2,     rightBack,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C1_6,    goalCapture,          tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "fourWheelMovement.c"
#include "rpgCommon.c"
#include "MovementCommon.c"
#include "gyroSensor.c"

task main()
{
	wait1Msec(1000);
	travelDistance(30, dForward);
	wait1Msec(1000);
	gyroTurn(30, 90, dLeft);
	wait1Msec(1000);
	travelDistance(30, dForward);
	gyroTurn(30, 90, dRight);
	wait1Msec(1000);
	travelDistance(30, dBackward);
	wait1Msec(1000);
	gyroTurn(30, 90, dRight);
	wait1Msec(1000);
	travelDistance(30, dForward);
	wait1Msec(1000);
	gyroTurn(30, 90, dLeft);
	wait1Msec(1000);
	gyroTurn(30, 360, dRight);
	wait1Msec(1000);
	strafe(-100);
	wait1Msec(750);
	stopMotors();
	wait1Msec(1000);
	strafe(100);
	wait1Msec(750);
	stopMotors();
}
