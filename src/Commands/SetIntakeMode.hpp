#pragma once

#include "Commands/Command.h"
#include "Main.h"

/**
 *
 *
 * @author ExampleAuthor
 */


enum IntakeMode
{
	STOPPED = 1,
	FORWARD = 2,
	REVERSE = 3,
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
				Main::getIntake().SetIntakeSpeed(1.0);
				break;
				case REVERSE:
				Main::getIntake().SetIntakeSpeed(-1.0);
				break;
				default:
				break;
			}
		}
		virtual bool IsFinished() { return false; }
		virtual void End() {}
		virtual void Interrupted() {}

};
