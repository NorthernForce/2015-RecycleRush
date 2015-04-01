#pragma once
#include "../WPILib.h"
#include "Commands/Command.h"
#include "Subsystems/MecanumDrive.h"
#include "Subsystems/PneumaticSubsystem.h"
#include "Subsystems/IntakeSubsystem.h"
#include "Subsystems/LimitSwitch.h"
#include "Subsystems/LedDisplay.h"
#include "OI.h"
#include "Commands/NormalAuto.cpp"
#include "Commands/DriveForwardAuto.cpp"

class Main : public IterativeRobot
{
	public:
		Main();
		virtual ~Main();

		static Main& 				getRobot();
		static MecanumDrive& 		getDrive();
		static PneumaticSubsystem&  getPneumatics();
		static IntakeSubsystem&     getIntake();
		static LimitSwitch&			getLimit();
		static LedDisplay&			getLed();
		static OI& 					getOI();


	private:
		LiveWindow 		   *lw;
		Command            *m_auto;
		SendableChooser    *m_chooser;
		MecanumDrive  	   m_drive;
		PneumaticSubsystem m_pneumatics;
		IntakeSubsystem    m_intake;
		LimitSwitch		   m_limit;
		LedDisplay		   m_led;
		OI				   m_oi;

		virtual void RobotInit();
		virtual void AutonomousInit();
		virtual void AutonomousPeriodic();
		virtual void TeleopInit();
		virtual void TeleopPeriodic();
		virtual void TestPeriodic();
};

