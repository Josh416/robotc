#pragma config(Hubs,  S1, HTMotor,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     IR,             sensorHiTechnicIRSeeker1200)
#pragma config(Sensor, S4,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Motor,  mtr_S1_C1_1,     leftFront,     tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C1_2,     leftBack,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S1_C2_1,     rightFront,    tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     rightBack,     tmotorTetrix, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*This is a set of movement functions.  Goals: make the robot go forward, backwards, turn,
and go to the side.  */
#include "fourWheelMovement.c"

task main()
{
forward(50);
wait1Msec(2000);
stopMotors();
wait1Msec(500);
backward(50);
wait1Msec(2000);
stopMotors();
}
