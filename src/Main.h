#pragma once
#include "WPILib.h"
#include "Commands/Command.h"
#include "Subsystems/MecanumDrive.h"
#include "OI.h"

class Main : public IterativeRobot {
public:
	Main();
	virtual ~Main();

	static Main& 				getRobot();
	static MecanumDrive& 		getDrive();
	static OI& 					getOI();

	//static BallCmdServer& getBall();

private:
	LiveWindow 		*lw;
	MecanumDrive 	s_drive;
	OI				oi;

	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};

