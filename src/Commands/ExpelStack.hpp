#pragma once

#include "Commands/Command.h"
#include "Main.h"


class ExpelStack: public Command
{
	public:
		ExpelStack()
		{
			Requires (&Main::getIntake());
			Requires (&Main::getDrive());
		}

		virtual void Initialize() {}

		virtual void Execute()
		{
			if(TimeSinceInitialized() < 3)
			{
				Main::getIntake().SetIntakeSpeed(.1);
				Main::getDrive().DriveMecanum(0.0, -0.1, 0.0);
			}
		}

		virtual bool IsFinished() { return false; }

		virtual void End()
		{
			Main::getIntake().SetIntakeSpeed(0);
			Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
		}

		virtual void Interrupted() {}
};
