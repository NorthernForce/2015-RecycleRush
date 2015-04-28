
#include "TriggerIntake.h"
#include "../Main.h"



TriggerIntake::TriggerIntake() {}

void TriggerIntake::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void TriggerIntake::Execute()
{
	//float x = Main::getOI().GetXBoxManipulatorStick().GetXBOXTrigger();

	//SmartDashboard::PutNumber(" Trigger", x);

	//float y = Main::getOI().GetXBoxManipulatorStick().GetLeftTrigger();

	//Main::getOI().GetXBoxManipulatorStick().SetRumble(Joystick::kRightRumble, 1.0);


	//Main::getIntake().SetIntakeSpeed(x);
	//Main::getOI().GetXBoxManipulatorStick().SetRumble(Joystick::kRightRumble, x);
	//Main::getIntake().SetIntakeSpeed(-y);
	//Main::getOI().GetXBoxManipulatorStick().SetRumble(Joystick::kLeftRumble, y);
}

// This is a default command which should never stop, except when kicked off by another command.
bool TriggerIntake::IsFinished()
{
	return false;
}

void TriggerIntake::End() {}

void TriggerIntake::Interrupted() {}




