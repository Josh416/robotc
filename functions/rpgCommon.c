#include "JoystickDriver.c"

#define nxtOrange 3
#define nxtLeft 2
#define nxtRight 1
#define nxtGrey 0
#define noButton -1

// Function: waitForStartOrButton
// Parameters:none
// this funcation lets you press a button or wait for the start of the program
//Outputs: none
void waitForStartOrButton()
{
	while (true)
	{
		getJoystickSettings(joystick);
		if (!joystick.StopPgm)      // normal FCS start condition
		{
			break;
		}

		if (nNxtButtonPressed == nxtOrange)
		{ // manual bypass start condition

			// 2 beeps and 2 seconds to get out of the way before the program starts
			playImmediateTone(1000,50);
			wait1Msec(1000);

			playImmediateTone(1000,50);
			wait1Msec(1000);

			break;
		}
	}
	return;
}
// Function: waitTillNoButton
// Parameters:none
// this funcation lets you wait till no button is pressed
//Outputs: none

void waitTillNoButton()
{
	while(nNxtButtonPressed != noButton)
	{

	}
}

// Function: resetEndcoders
// Parameters:none
// this funcation resets the encoders
//Outputs: none

/*void resetEncoders()
{
	nMotorEncoder[rightFront] = 0;
	//nMotorEncoder[rightBack] = 0;
	nMotorEncoder[leftFront] = 0;
	//nMotorEncoder[leftBack] = 0;
}*/