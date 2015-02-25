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
		}

		virtual bool IsFinished(){return false;}

		virtual void End()
		{}

		virtual void Interrupted() {}
};

