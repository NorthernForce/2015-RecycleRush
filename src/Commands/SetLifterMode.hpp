#pragma once

#include "Commands/Command.h"
#include "Main.h"


enum LifterMode
{
	UP = 1,
	DOWN = 2,
};

template<int mode>
class SetLifterMode: public Command
{
	public:
		SetLifterMode()
		{
			Requires(&Main::getPneumatics());
		}

		virtual void Initialize() {}

		virtual void Execute()
		{
			switch(mode)
			{
				case UP:
					Main::getPneumatics().SetToteLifter();
					Main::getPneumatics().SetBinHolder();
				break;

				case DOWN:
					Main::getPneumatics().ResetToteLifter();
				break;
			}
		}

		virtual bool IsFinished(){return false;}

		virtual void End() {}

		virtual void Interrupted() {}
};

