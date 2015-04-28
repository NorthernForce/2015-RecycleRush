#pragma once

#include "Commands/Command.h"
#include "Main.h"



enum WheelMode
{
	ACTUATE = 1,
	UNACTUATE = 2,
};


template <int mode>
class SetWheelMode: public Command
{
	public:
		SetWheelMode() { Requires(&Main::getPneumatics()); }
		virtual void Initialize() {}
		virtual void Execute()
		{
			switch(mode)
			{
				case ACTUATE:
				Main::getPneumatics().SetWheelActuator();
				SmartDashboard::PutBoolean(" Wheel Actuator: ", true);  //Added for driver, boolean box in the (old) Smart Dashboard
																		//in the (old) Smart Dashboard
				break;

				case UNACTUATE:
				Main::getPneumatics().ResetWheelActuator();
				SmartDashboard::PutBoolean(" Wheel Actuator: ", false); //Added for driver, boolean box in the (old) Smart Dashboard
																		//in the (old) Smart Dashboard
				break;

				default:
				break;
			}

		}
		virtual bool IsFinished() { return false; }
		virtual void End() {}
		virtual void Interrupted() {}

};
