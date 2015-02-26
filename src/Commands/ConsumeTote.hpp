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
		}

		virtual bool IsFinished() { return false; }

		virtual void End()
		{
			Main::getPneumatics().ResetToteLifter();
		}

		virtual void Interrupted() {}
};

