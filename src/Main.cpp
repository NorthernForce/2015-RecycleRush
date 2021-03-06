#include "Main.h"

Main::Main() : lw(0), autocmd()
{}

Main::~Main()
{
	delete autocmd;
}

Main& Main::getRobot()
{
	return static_cast<Main&>(RobotBase::getInstance());
}


MecanumDrive& Main::getDrive()
{
	return getRobot().m_drive;
}

PneumaticSubsystem& Main::getPneumatics()
{
	return getRobot().m_pneumatics;
}

IntakeSubsystem& Main::getIntake()
{
	return getRobot().m_intake;
}

LimitSwitch& Main::getLimit()
{
	return getRobot().m_limit;
}

LedDisplay& Main::getLed()
{
	return getRobot().m_led;
}

OI& Main::getOI()
{
	return getRobot().m_oi;
}

void Main::RobotInit()
{
	m_oi.init();
	m_drive.init();
	m_pneumatics.init();
	m_intake.init();


	autocmd = new Auto();
	lw = LiveWindow::GetInstance();
}

void Main::AutonomousInit()
{
	autocmd->Start();
}

void Main::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Main::TeleopInit()
{
	//Main::getPneumatics().SetToteLifter();
}

void Main::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Main::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Main);

