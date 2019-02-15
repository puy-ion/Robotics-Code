#pragma config(Sensor, dgtl1,  rightin,        sensorQuadEncoder)
#pragma config(Motor,  port1,           motor1,        tmotorVex393_HBridge, openLoop)
#pragma config(Motor,  port2,           motor2,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port3,           motor3,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port4,           launcher1,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           launcher2,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           motor6,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port6,           motor7,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port7,           launchers,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          motor10,       tmotorVex393_HBridge, openLoop, driveLeft)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//
//#pragma config(Motor,  port8,           arm_motor,     tmotorVex393_MC29, openLoop)
// This code is for the VEX cortex platform
#pragma platform(VEX2)

// Select Download method as "competition"
#pragma competitionControl(Competition)

//Main competition background code...do not modify!
#include "Vex_Competition_Includes.c"

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the cortex has been powered on and    */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton()
{
  // Set bStopTasksBetweenModes to false if you want to keep user created tasks
  // running between Autonomous and Driver controlled modes. You will need to
  // manage all user created tasks if set to false.
  bStopTasksBetweenModes = true;

	// Set bDisplayCompetitionStatusOnLcd to false if you don't want the LCD
	// used by the competition include file, for example, you might want
	// to display your team name on the LCD in this function.
	// bDisplayCompetitionStatusOnLcd = false;

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...

  //SensorType[dgtl1] = sensorNone;
	//wait1Msec(1000);
	//SensorType[dgtl1] = sensorQuadEncoder;
	//wait1Msec(2000);
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task autonomous()
{
	//AutonomousCodePlaceholderForTesting();
	//move motor forward
	motor[launcher1] = 120;
	motor[launcher2] = -120;
	motor[motor1] = -80;
	motor[motor2] = -80;
	motor[motor3] = 80;
	motor[motor10] = 80;
	wait1Msec(600);
	motor[launchers] = -127;
	motor[motor1] = 0;
	motor[motor2] = 0;
	motor[motor3] = 0;
	motor[motor10] = 0;
	wait1Msec(300);
	motor[motor1] = -50;
	motor[motor2] = -50;
	motor[motor3] = 50;
	motor[motor10] = 50;
	wait1Msec(2000);

}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

task usercontrol()
{
  // User control code here, inside the loop
	int state=0, preState=0;
  while (true)
  {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................


		//int initial_sensor = SensorValue[rightin];
		while(1==1){
			//DRIVING///////////////////////////////////////////////////////////////////
			//port 1 is connected to motor 5
			motor[motor1] = (vexRT[Ch3]*-1 + vexRT[Ch4]);

			//port 2 is connected to motor 4 and 6
			motor[motor2] = (vexRT[Ch3]*-1 + vexRT[Ch4]*-1);

			//port 3 is connected to motor 1 and 3
			motor[motor3] = (vexRT[Ch3] + vexRT[Ch4]*-1);

			//port 10 is connected to motor 2
			motor[motor10] = (vexRT[Ch3] + vexRT[Ch4]);
			////////////////////////////////////////////////////////////////////////////

			//Launcher controls
			//port 6 connected to motor 11
			motor[launchers] = vexRT(Ch2);
			if (vexRT[Btn8R] == 1){
				motor[launchers] = -127;
			}

			//sauce thing flipper
			if (vexRT[Btn8L] == 1){
				motor[launchers] = 127;

			}

			//port 4 connected to motor 7 and 8
			//port 5 connected to motor 9 and 10
			if (vexRT[Btn5D]==0){
				preState = 0;
			}
			if (vexRT[Btn5D] == 1 && preState ==0){
				preState = 1;
				state = state == 0? 1:0;
			}
			motor[launcher1] = state*127;
			motor[launcher2] = -state*127;
			//arm controls
			//port 7 connected to motor 12
			if (vexRT[Btn8D] == 1){
				motor[motor7] = -45;
				wait1Msec(120);
				motor[motor7] = -75;
				wait1Msec(800);
				motor[motor7] = 25;
				wait1Msec(200);
				motor[motor7] = 0;
			}
			if (vexRT[Btn8U] == 1){
				motor[motor7] = 90;
				wait1Msec(450);
				motor[motor7] = -10;
				wait1Msec(600);
				motor[motor7] = 0;

			}
	 }
 }
}