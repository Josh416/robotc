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

#define MUX1 		 msensor_S4_1
#define touch 	 msensor_S4_2
#define sonar    msensor_S4_3

#define GOVLIMIT 3000
float GOVERNOR

#include "IRsensor.c"
#include "fourWheelMovement.c"
#include "gyroSensor.c"
#include "MovementCommon.c"

/*This is a set of movement functions.  Goals: make the robot go forward, backwards, turn,
and go to the side.  */
#include "lego-touch.h"

#define deadZone 20

const tMUXSensor LTOUCH = msensor_S4_1;

task main()
{
	disableDiagnosticsDisplay();

	while(true) {
		getJoystickSettings(joystick);  // Update Buttons and Joysticks
	delay(10);

		/*--------------------------
		controller one
		-------------------------*/
		/*-------------------------
		maping
		---------------------------
		up =
		down =
		left = strafe left
		right = strafe right
		joystick left = left motors
		joystick right = right motors
		A = catcher down
		B =	catcher up
		X =
		Y =
		L1 =
		L2 =
		R1 =
		R2 =
		---------------------------*/

		// If lift is too high slower the driver motors
		if(nMotorEncoder[liftRight] < GOVLIMIT) {
			GOVERNOR = 1;
		} else {
		  GOVERNOR = 2;
		}

		// Drive the robot from joystick 1
		if((abs(joystick.joy1_y1) >= deadZone) || (abs(joystick.joy1_y2) >= deadZone)) {
			setMotion(joystick.joy1_y1 / GOVERNOR, joystick.joy1_y2 / GOVERNOR);
		}
		else if(joystick.joy1_TopHat == 6) {
			strafe(50);
		}
		else if(joystick.joy1_TopHat == 2){
			strafe(-50);
		}
		else {
			stopMotors();
		}
	/*
	if(joy1Btn(JOY_BUTTON_A))
	{
		int iCRate = servoChangeRate[goalCapture];	// Save change rate
		servoChangeRate[goalCapture] = 0; 					// Max Speed
		servo[goalCapture] = 105;					// Set servo position
		wait1Msec(20);
		servoChangeRate[goalCapture] = iCRate;			// Reset the servo
	}
	else if(joy1Btn(JOY_BUTTON_B))
	{
		int iCRate = servoChangeRate[goalCapture];	// Save change rate
		servoChangeRate[goalCapture] = 0; 					// Max Speed
		servo[goalCapture] = 200;					// Set servo position
		wait1Msec(20);
		servoChangeRate[goalCapture] = iCRate;			// Reset the servo
	}
*/
		// Capture/release a goal with the end servo
		if(joy1Btn(JOY_BUTTON_A)) {
			int iCRate = servoChangeRate[goalCapture];	// Save change rate
			servoChangeRate[goalCapture] = 0; 					// Max Speed
			servo[goalCapture] = 0;					// Set servo position
			wait1Msec(20);
			servoChangeRate[goalCapture] = iCRate;			// Reset the servo
		}
		else if(joy1Btn(JOY_BUTTON_B)) {
			int iCRate = servoChangeRate[goalCapture];	// Save change rate
			servoChangeRate[goalCapture] = 0; 					// Max Speed
			servo[goalCapture] = 255;					// Set servo position
			wait1Msec(20);
			servoChangeRate[goalCapture] = iCRate;			// Reset the servo
		}

	/*--------------------------
	controller two
	-------------------------*/
	/*-------------------------
	maping
	---------------------------
	up =
	down =
	left =
	right =
	joystick left =
	joystick right =
	A =
	B =
	X =
	Y =
	LB = big backward
	LT = big forward
	RB = small backward
	RT = small forward
	---------------------------*/
		// Raise/lower the lift
		if(abs(joystick.joy2_y2) > deadZone) {
			stopLiftTask();

			// if touchsensor hit and lift down stop
			if((joystick.joy2_y2 <= 0) && TSreadState(LTOUCH)) { // /* == 1*/) {
				lift(0);
				nMotorEncoder[liftRight] = 0;
			} else {
					lift(rescale(joystick.joy2_y2));
			}
		} else {
			lift(0);
		}

		// Set the lift to preset heights
		if(joy2Btn(JOY_BUTTON_A)) {
			liftHeight(35);
		} else if(joy2Btn(JOY_BUTTON_B)) {
			liftHeight(65);
		}	else if(joy2Btn(JOY_BUTTON_Y)) {
			liftHeight(95);
		} else if(joy2Btn(JOY_BUTTON_X)) {
			liftHeight(115);
		} else if(joy2Btn(JOY_BUTTON_RT)) {
			liftHeight(0);
			nMotorEncoder[liftRight] = 0;
		}

		// Run the spinner to pick up balls
		if((abs(joystick.joy2_y1)) >= deadZone) {
			spin(rescale(joystick.joy2_y1));
		} else {
			spin(0);
		}
	}
}
