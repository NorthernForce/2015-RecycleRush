#include "Main.h"

Main::Main() : lw(0) {}

Main::~Main(){}

Main& Main::getRobot() {
	return static_cast<Main&>(RobotBase::getInstance());
}


MecanumDrive& Main::getDrive() {
	return getRobot().s_drive;
}

PneumaticSubsystem& Main::getPneumatics()
{
	return getRobot().s_pneumatics;
}

IntakeSubsystem& Main::getIntake()
{
	return getRobot().s_intake;
}


OI& Main::getOI() {
	return getRobot().oi;
}

void Main::RobotInit() {
	oi.init();
	s_drive.init();
	lw = LiveWindow::GetInstance();
}

void Main::AutonomousInit() {
}

void Main::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

void Main::TeleopInit() {
	//s_drive.SetAxes(0.5, 0.5);
}

void Main::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();


}

void Main::TestPeriodic() {
	lw->Run();
}

START_ROBOT_CLASS(Main);

