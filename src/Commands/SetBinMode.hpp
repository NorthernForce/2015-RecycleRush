#pragma once

#include "Commands/Command.h"
#include "Main.h"


enum BinMode
{
	IN = 1, 
	OUT = 2,
};

template<int mode>
class SetBinMode: public Command
{
	public:
		SetBinMode()
		{
			Requires(&Main::getPneumatics());
		}

		virtual void Initialize() {}

		virtual void Execute()
		{
			switch(mode)
			{
				case IN:
					Main::getPneumatics().SetBinHolder();
				break;
				
				case OUT; 
					Main::getPneumatics().ResetBinHolder();
				break;
				
				break;
				default;
				break;
		}

		virtual bool IsFinished() { return false; }

		virtual void End()
		{
			//Main::getPneumatics().ResetBinHolder();
		}

		virtual void Interrupted() {}
};
