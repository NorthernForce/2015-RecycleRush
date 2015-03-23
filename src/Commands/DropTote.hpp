#pragma once

#include "Commands/Command.h"
#include "Main.h"


class DropTote: public Command
{
	public:
		DropTote()
		{
			Requires(&Main::getPneumatics());
		}

		virtual void Initialize() {}

		virtual void Execute()
		{
			Main::getPneumatics().ResetToteLifter();
			Main::getPneumatics().SetBinHolder();   //Added to retract top pistons when the pauls (lifters) are down
		}

		virtual bool IsFinished(){return false;}

		virtual void End()
		{}

		virtual void Interrupted() {}
};

