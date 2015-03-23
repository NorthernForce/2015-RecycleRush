#pragma once

#include "Commands/Command.h"
#include "Main.h"


class HoldBin: public Command
{
	public:
		HoldBin()
		{
			Requires(&Main::getPneumatics());
		}

		virtual void Initialize() {}

		virtual void Execute()
		{
			Main::getPneumatics().SetBinHolder();
		}

		virtual bool IsFinished() { return false; }

		virtual void End()
		{
			//Main::getPneumatics().ResetBinHolder();
		}

		virtual void Interrupted() {}
};
