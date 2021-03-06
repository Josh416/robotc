#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     smux,           sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_1,     rightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_2,     rightBack,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C1_6,    goalCapture,          tServoStandard)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

//This is the 4-wheel mecanum pragmas
#pragma config(Hubs,  S1, HTMotor,  HTMotor,  HTMotor,  none)
#pragma config(Hubs,  S2, HTServo,  HTMotor,  none,     none)
#pragma config(Sensor, S3,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     smux,           sensorI2CCustom)
#pragma config(Motor,  mtr_S1_C1_1,     spinner,       tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_1,     leftFront,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C2_2,     leftBack,      tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_1,     liftRight,     tmotorTetrix, openLoop)
#pragma config(Motor,  mtr_S1_C3_2,     liftLeft,      tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_1,     rightFront,    tmotorTetrix, openLoop, reversed)
#pragma config(Motor,  mtr_S2_C2_2,     rightBack,     tmotorTetrix, openLoop, reversed)
#pragma config(Servo,  srvo_S2_C1_6,    goalCapture,          tServoStandard)

//This is the 2-wheel pragmas
#pragma config(Motor,  motorA,           ,             tmotorNXT, openLoop)
#pragma config(Motor,  motorB,          leftFront,     tmotorNXT, PIDControl)
#pragma config(Motor,  motorC,          rightFront,    tmotorNXT, PIDControl)


//sensors
#pragma config(Sensor, S3,     gyro,           sensorI2CHiTechnicGyro)
#pragma config(Sensor, S4,     smux,           sensorI2CCustom)

//Mux

#define MUX1 		 msensor_S4_1
#define touch 	 msensor_S4_2
#define sonar	 	 msensor_S4_3
