#pragma once

#include "Commands/Command.h"
#include "Main.h"


enum BinOrienterMode
{
	DOWN = 1, 
	UP = 2,
};

template<int mode>
class SetBinOrienterMode: public Command
{
	public:
		SetBinOrienterMode()
		{
			Requires(&Main::getPneumatics());
		}

		virtual void Initialize() {}

		virtual void Execute()
		{
			switch(mode)
			{
				case DOWN:
					Main::getPneumatics().SetBinOrienter();
				case UP:
					Main::getPneumatics().ResetBinOrienter();

		}

		virtual bool IsFinished() { return false;}

		virtual void End() {}

		virtual void Interrupted() {}
};

