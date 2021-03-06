#pragma config(Sensor, in1,    p,              sensorPotentiometer)
#pragma config(Motor,  port1,            ,             tmotorVex393TurboSpeed_HBridge, openLoop)
#pragma config(Motor,  port2,           angler,        tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port3,           shooter,       tmotorVex393TurboSpeed_MC29, openLoop)
#pragma config(Motor,  port4,           intake,        tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port5,           leftws,        tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port6,           rightws,       tmotorVex393TurboSpeed_MC29, openLoop, reversed)
#pragma config(Motor,  port7,           arms,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port8,           claw,          tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,           ,             tmotorVex393_HBridge, openLoop)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{

	bool myClaw = false; // Determines wheater the next flip will flip left or right
	int spinTime = 200;  // Time for 1 flip
	int state=0, preState=0;
	int ts = 1, prestate1 = 0;
	SensorValue[p] = 0;
	int thr = 600;
	int angle = 0;
	bool punch = false;

	while (true){
		//motor[shooter] = -127;
		//angle = 0;
		if (vexRT[Btn5D] == 1){
			angle = 1400;
			punch = true;
		}

		else if (vexRT[Btn5U] == 1){
			angle = 4000;
			punch = true;
		}
		else{
			angle = 0;
			punch = false;
		}

		if (angle !=0){
			if (abs(SensorValue[p]-angle)>30){
				if (abs(SensorValue[p]-angle)<thr){
					if (SensorValue[p]-angle<thr){
						motor[angler] = 10;

					}
					else if (SensorValue[p]-angle>-thr){
						motor[angler] = -10;

					}

				}
				else{
					if (SensorValue[p]-angle>thr){
						motor[angler] = 110;
					}
					else if (SensorValue[p]-angle<-thr){
						motor[angler] = -110;
					}
				}
			}



		}

		//}

		if (punch == true){
			motor[shooter] = -127;
		}
		else{
			motor[shooter] = 0;
		}



		if (vexRT[Btn8U] == 1){
			motor[intake] = -127;
		}
		else if (vexRT[Btn8D] == 1){
			motor[intake] = 127;
		}
		else{
			motor[intake] = 0;
		}

		int a = -(vexRT[Ch3] + vexRT[Ch4]*0.8 + vexRT[Ch3Xmtr2] + vexRT[Ch4Xmtr2]*0.8);
		int b =  -(vexRT[Ch3]*-1+vexRT[Ch4]*0.8 + vexRT[Ch3Xmtr2]*-1+vexRT[Ch4Xmtr2]*0.8);
		if (vexRT[Btn8L]==1&&prestate1==0){
			if (ts==1) ts = 0;
			else ts = 1;
			prestate1 = 1;
		}
		if (vexRT[Btn8L] ==0 &&prestate1==1){
			prestate1 = 0;
		}
		if (ts==1){
			motor[leftws] = a;


			motor[rightws] = b;

		}
		else{
			motor[leftws] = b;


			motor[rightws] = a;
		}
		if (vexRT[Btn7U] == 1){
			motor[arms] = 127;
			//wait1Msec(100);
	  }
	  else if (vexRT[Btn7D] == 1){
	  	motor[arms] = - 127;
	  	//wait1Msec(500);
	  }
	  else{
	  	motor[arms] = 0;
	  }
	  if (vexRT[Btn7L] == 1){
	  	if (myClaw){
				motor[claw] = 127;
				wait1Msec(spinTime);
			}
			else {
				motor[claw] = -127;
				wait1Msec(spinTime);
			}
			myClaw = !myClaw
			motor[claw] = 0;
	  }
	}
}
