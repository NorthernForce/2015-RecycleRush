#pragma once

#include "Commands/Command.h"
#include "Main.h"



enum WheelMode
{
	IN = 1,
	OUT = 2,
};


template <int mode>
class ActuateWheels: public Command
{
	public:
		ActuateWheels() { Requires(&Main::getPneumatics()); }
		virtual void Initialize() {}
		virtual void Execute()
		{
			switch(mode)
			{
				case IN:
				Main::getPneumatics().SetWheelActuator();
				SmartDashboard::PutBoolean("LOOK HERE!!!! Actuator: ", true);
				break;
				case OUT:
				Main::getPneumatics().ResetWheelActuator();
				SmartDashboard::PutBoolean("LOOK HERE!!!! Actuator: ", false);

				break;
				default:
				break;

			}

		}
		virtual bool IsFinished() { return false; }
		virtual void End() {}
		virtual void Interrupted() {}

};
