#pragma once

#include "Commands/Command.h"
#include "Main.h"



enum IntakeMode
{
	STOPPED = 1,
	FORWARD = 2,
	REVERSE = 3,
	OPPOSITE1 = 4,
	OPPOSITE2 = 5,
};


template <int mode>
class SetIntakeMode: public Command
{
	public:
		SetIntakeMode() { Requires(&Main::getIntake()); }
		virtual void Initialize() {}
		virtual void Execute()
		{
			switch(mode)
			{
				case STOPPED:
				Main::getIntake().SetIntakeSpeed(0.0);
				break;
				case FORWARD:
				Main::getIntake().SetIntakeSpeed(1);
				break;
				case REVERSE:
				Main::getIntake().SetIntakeSpeed(-1);
				break;
				case OPPOSITE1:
				Main::getIntake().SetReverseIntakeSpeed(1);
				break;
				case OPPOSITE2:
				Main::getIntake().SetReverseIntakeSpeed(-1);
				break;
				default:
				break;

			}

			Main::getIntake().GetIntakeSpeed();

		}
		virtual bool IsFinished() { return false; }
		virtual void End() {}
		virtual void Interrupted() {}

};
