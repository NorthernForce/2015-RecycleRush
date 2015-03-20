#pragma once

#include "Commands/Command.h"
#include "Main.h"


class RightBin: public Command
{
	public:
		RightBin()
		{
			Requires(&Main::getPneumatics());
			Requires(&Main::getDrive());
		}

		virtual void Initialize() {}

		virtual void Execute()
		{


				Main::getPneumatics().SetBinOrienter();
				Main::getDrive().DriveMecanum(0.0, 0.1, 0.0);

		}

		virtual bool IsFinished() { return false;}

		virtual void End()
		{
			Main::getPneumatics().ResetBinOrienter();
			Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
		}

		virtual void Interrupted() {}
};

