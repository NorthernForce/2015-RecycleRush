#pragma once

#include "Commands/Command.h"
#include "Main.h"



enum WedgeMode
{
	ACTUATED = 1,
	UNACTUATED = 2,
};


template <int mode>
class SetWedgeMode: public Command
{
	public:
		SetWedgeMode() { Requires(&Main::getPneumatics()); }
		virtual void Initialize() {}
		virtual void Execute()
		{
			switch(mode)
			{
				case ACTUATED:
				Main::getPneumatics().SetWedgeBar();
				SmartDashboard::PutBoolean(" Wedge Bar", false);
				break;

				case UNACTUATED:
				Main::getPneumatics().ResetWedgeBar();
				SmartDashboard::PutBoolean(" Wedge Bar", true);
				break;

				default:
				break;
			}

		}
		virtual bool IsFinished() { return false; }
		virtual void End() {}
		virtual void Interrupted() {}

};
