#include "Main.h"

Main::Main() : lw(0), m_auto(), m_chooser()
{}

Main::~Main()
{
	delete m_auto;
	delete m_chooser;
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

	m_chooser = new SendableChooser();
	m_chooser->AddDefault("Normal Auto", new NormalAuto());
	m_chooser->AddObject("Drive Forward", new DriveForwardAuto());
	SmartDashboard::PutData("Autonomous Modes", m_chooser);

	lw = LiveWindow::GetInstance();
}

void Main::AutonomousInit()
{
	m_auto = (Command *) chooser->GetSelected();
	m_auto->Start();
}

void Main::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Main::TeleopInit()
{}

void Main::TeleopPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Main::TestPeriodic()
{
	lw->Run();
}

START_ROBOT_CLASS(Main);

