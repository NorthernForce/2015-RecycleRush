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
	// Y velocity
	float y = Main::getOI().GetDriverStick().GetLeftStickY();
	// Angular velocity
	float w = Main::getOI().GetDriverStick().GetRightStickX();

	//Send joystick values to SmartDashboard
	SmartDashboard::PutNumber("Left Stick X Value: ", x);
	SmartDashboard::PutNumber("Left Stick Y Value: ", y);
	SmartDashboard::PutNumber("Right Stick X Value: ", w);


	//Adjusts the joystick values according to a log scale

	if (x > 0.5)
		x = log(x);
	else if (x < -0.5)
		x = -log(-x);

	if (y > 0.5)
		y = log(y);
	else if (y < -0.5)
		y = -log(-y);

	if (w > 0.5)
		w = log(w);
	else if (w < -0.5)
		w = -log(-w);


	// Sends command to drive subsystem

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

