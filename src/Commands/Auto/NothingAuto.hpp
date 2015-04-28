#pragma once

#include "Main.h"

class NothingAuto : public Command
{
	public:

		NothingAuto()
		{}

		void Initialize()
		{
			//Main::getPneumatics().SetToteLifter();
		}

		void Execute()
		{}

		bool IsFinished()
		{
			return true;
		}

		void End()
		{}

		void Interrupted() {}

};
