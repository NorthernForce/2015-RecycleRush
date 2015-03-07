
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

	if(t < 1)
	{
		Main::getDrive().DriveMecanum(0.0, 0.5, 0.0);
	}

	else if(t < 3)
	{
		Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
		Main::getPneumatics().SetToteLifter();
	}

	else if(t < 5)
	{
		Main::getDrive().DriveMecanum(0.0, -0.5, 0.0);
	}

	else if(t < 6)
	{
		Main::getDrive().DriveMecanum(-0.5, 0.0, 0.0);
	}

	else if(t < 7)
	{
		Main::getIntake().SetIntakeSpeed(0.5);
		Main::getDrive().DriveMecanum(0.0, 0.1, 0.0);
	}

	else if(t < 8)
	{
		Main::getIntake().SetIntakeSpeed(0.0);
		Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
		Main::getPneumatics().ResetToteLifter();
	}

	else if (t < 9)
	{
		Main::getPneumatics().SetToteLifter();
	}

	else if (t < 10)
	{
		Main::getDrive().DriveMecanum(0.0, -1.0, 0.0);
	}


}

bool Auto::IsFinished()
{
	return TimeSinceInitialized() > 11;
}

void Auto::End()
{
	Main::getIntake().SetIntakeSpeed(0.0);
	Main::getPneumatics().ResetToteLifter();
	Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
}

void Auto::Interrupted() {}



