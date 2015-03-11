
#include "Auto.h"
#include "../Main.h"

Auto::Auto()
{
	Requires (&Main::getPneumatics());
	Requires (&Main::getIntake());
	Requires (&Main::getDrive());
}

void Auto::Initialize() {}

void Auto::Execute()
{
	double t = TimeSinceInitialized();

	double mode = 1.0;

	SmartDashboard::GetNumber("Autonomous Mode", mode);

	Main::getPneumatics().SetToteLifter();

if(mode == 1.0)
{
	if(t > 3 && t < 5)
	{
		Main::getDrive().DriveMecanum(0.0, 0.3, 0.0);
	}

	else if(t > 5 && t < 6)
	{
		Main::getDrive().DriveMecanum(0.0, 0.0, 0.58);
		Main::getIntake().SetIntakeSpeed(0.0);
	}

	else if(t > 6 && t < 7.5)
	{
		Main::getDrive().DriveMecanum(0.0, 0.6, 0.0);
	}

	else if (t > 7)
	{
		Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
	}
}

else if(mode == 2.0)
{
	if(t > 3 && t < 5)
	{
		Main::getDrive().DriveMecanum(0.0, 0.3, 0.0);
	}

	else if(t > 5 && t < 6)
	{
		Main::getDrive().DriveMecanum(0.0, 0.0, 0.5);
		Main::getIntake().SetIntakeSpeed(0.0);
	}

	else if(t > 6 && t < 7.5)
	{
		Main::getDrive().DriveMecanum(0.0, 0.8, 0.0);
	}

	else if (t > 7)
	{
		Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
	}
}

}


bool Auto::IsFinished()
{
	return TimeSinceInitialized() > 11;
}

void Auto::End()
{
	Main::getIntake().SetIntakeSpeed(0.0);
	Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
}

void Auto::Interrupted() {}



