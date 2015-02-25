#include "DriveWithJoystick.h"
#include "../Main.h"
#include <cmath>


DriveWithJoystick::DriveWithJoystick()
{
	Requires(&Main::getDrive());
}

void DriveWithJoystick::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void DriveWithJoystick::Execute()
{
	// X velocity
	float x = Main::getOI().GetDriverStick().GetLeftStickX();
	//x *= fabs(x);
	// Y velocity
	float y = Main::getOI().GetDriverStick().GetLeftStickY();
	//y *= fabs(y);
	// Angular velocity
	float w = Main::getOI().GetDriverStick().GetRightStickX();
	//w *= fabs(w);

	//Send joystick values to SmartDashboard
	SmartDashboard::PutNumber("Left Stick X Value: ", x);
	SmartDashboard::PutNumber("Left Stick Y Value: ", y);
	SmartDashboard::PutNumber("Right Stick X Value: ", w);

	std::cout << "X: " << x << " Y: " << y << " W: " << w << std::endl;
	// Send command to drive subsystem
	Main::getDrive().DriveMecanum(x, y, w);
}

// This is a default command which should never stop, except when kicked off by another command.
bool DriveWithJoystick::IsFinished()
{
	return false;
}

void DriveWithJoystick::End()
{
	printf("DriveWithJoystick Ended");
}

void DriveWithJoystick::Interrupted()
{
	printf("DriveWithJoystick Interrupted");
}

