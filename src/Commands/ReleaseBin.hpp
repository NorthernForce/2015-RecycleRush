#pragma once

#include "Commands/Command.h"
#include "Main.h"


class ReleaseBin: public Command
{
	public:
		ReleaseBin()
		{
			Requires (&Main::getPneumatics());
		}

		virtual void Initialize() {}

		virtual void Execute()
		{
			Main::getPneumatics().ResetBinHolder();
		}

		virtual bool IsFinished() { return false; }

		virtual void End()
		{
			//Main::getPneumatics().ResetBinHolder();
		}

		virtual void Interrupted() {}
};
