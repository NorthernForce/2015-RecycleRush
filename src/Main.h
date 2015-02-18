#pragma once
#include "WPILib.h"
#include "Commands/Command.h"
#include "Subsystems/MecanumDrive.h"
#include "Subsystems/PneumaticSubsystem.h"
#include "Subsystems/IntakeSubsystem.h"
#include "OI.h"

class Main : public IterativeRobot {
public:
	Main();
	virtual ~Main();

	static Main& 				getRobot();
	static MecanumDrive& 		getDrive();
	static PneumaticSubsystem&  getPneumatics();
	static IntakeSubsystem&     getIntake();
	static OI& 					getOI();
	static LimitSwitch&			getLimit();

	//static BallCmdServer& getBall();

private:
	LiveWindow 		   *lw;
	MecanumDrive  	   m_drive;
	PneumaticSubsystem m_pneumatics;
	IntakeSubsystem    m_intake;
	OI				   m_oi;
	LimitSwitch		   m_limit;


	virtual void RobotInit();
	virtual void AutonomousInit();
	virtual void AutonomousPeriodic();
	virtual void TeleopInit();
	virtual void TeleopPeriodic();
	virtual void TestPeriodic();
};

