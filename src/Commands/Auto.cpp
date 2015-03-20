
#include "Auto.h"
#include "../Main.h"

Auto::Auto()
{
	Requires (&Main::getPneumatics());
	Requires (&Main::getIntake());
	Requires (&Main::getDrive());
}

void Auto::Initialize()
{
	//Main::getPneumatics().SetToteLifter();
}

void Auto::Execute()
{
	double t = TimeSinceInitialized();

	double mode = 1.0;

	SmartDashboard::GetNumber("Autonomous Mode", mode);

/*************** Different Autonomous Modes *********************/

if(mode == 1.0)  //Starts at the back, bin inside, picks up, then drives forward. Barely makes it over ramp. WORKS
{
	if(t > 1 && t < 2)
	{
		Main::getPneumatics().ResetToteLifter();
	}

	else if(t > 5 && t < 7.3)
	{
		Main::getDrive().DriveMecanum(0.0, 0.5, 0.0);
	}

}


if(mode == 2.0)  //Starts paralell to back wall, rotates bin, drives forward
                 //and picks up, then strafes left into auto zone. WORKS
{
	if (t > 1 && t < 2)
	{
		Main::getPneumatics().SetToteLifter();
		Main::getIntake().SetReverseIntakeSpeed(0.2);
	}
	else if(t > 3 && t < 4.5)
	{
		Main::getIntake().SetIntakeSpeed(0.2);
		Main::getDrive().DriveMecanum(0.0, 0.2, 0.0);
	}

	else if(t > 5 && t < 6)
	{
		Main::getIntake().SetIntakeSpeed(0.0);
		Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
		Main::getPneumatics().ResetToteLifter();
	}

	else if(t > 7 && t < 11)
	{
		Main::getDrive().DriveMecanum(-0.6, 0.0, 0.0);
	}

}

if(mode == 3.0)  //Starts parallel to back wall, picks up bin, turns,
	             //drives forward into Auto zone. UNTESTED
{
	if (t > 1 && t < 2)
	{
		Main::getPneumatics().ResetToteLifter();
		Main::getIntake().SetReverseIntakeSpeed(0.3);
	}
	else if(t > 3 && t < 4)
	{
		Main::getDrive().DriveMecanum(0.0, 0.2, 0.0);
	}

	else if(t > 5 && t < 6)
	{
		Main::getPneumatics().SetToteLifter();
	}

	else if(t > 7 && t < 8)
	{
		Main::getDrive().DriveMecanum(0.0, 0.0, 0.5);
	}

	else if (t > 9 && t < 11)
	{
		Main::getDrive().DriveMecanum(0.0, 0.5, 0.0);
	}
	else if (t > 12)
	{
		Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
	}
}


else if(mode == 4.0)  // The original, with bump adjusted in (t > 6 && t < 7.5) line
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
	return TimeSinceInitialized() > 7.3; //For drive straight, mode 1.0
	//return TimeSinceInitialized() > 11; //For strafe, mode 2.0
	//return TimeSinceInitialized() > 12; //For bin, turn then drive, mode 3.0
	//return TimeSinceInitialized() > 7; //For Original, mode 4.0
}

void Auto::End()
{
	Main::getIntake().SetIntakeSpeed(0.0);
	Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
}

void Auto::Interrupted() {}



