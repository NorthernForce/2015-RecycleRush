#pragma once

#include "Commands/Command.h"
#include "Main.h"


class ReOrientBin: public Command
{
	public:
		ReOrientBin()
		{
			Requires(&Main::getPneumatics());
			//Requires(&Main::getDrive());
		}

		virtual void Initialize() {}

		virtual void Execute()
		{
			//if (TimeSinceInitialized() < 2)
			//{
				Main::getPneumatics().ResetBinOrienter();
				//Main::getDrive().DriveMecanum(0.0, -0.1, 0.0);
			//}
		}

		virtual bool IsFinished() { return false;}

		virtual void End()
		{
			//Main::getPneumatics().ResetBinOrienter();
			//Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
		}

		virtual void Interrupted() {}
};

