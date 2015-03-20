#pragma once

#include "Commands/Command.h"
#include "Main.h"


class ConsumeTote: public Command
{
	public:
		ConsumeTote()
		{
			Requires(&Main::getPneumatics());
		}

		virtual void Initialize() {}

		virtual void Execute()
		{
			Main::getPneumatics().SetToteLifter();
			Main::getPneumatics().SetBinHolder(); //Added to retract top pistons when the pauls (lifters) are up
		}

		virtual bool IsFinished(){return false;}

		virtual void End()
		{}

		virtual void Interrupted() {}
};

