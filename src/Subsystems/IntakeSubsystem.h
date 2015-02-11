#pragma once

#include "WPILib.h"
#include "SubsystemWithCommand.hpp"

class IntakeSubsystem : public SubsystemWithCommand<void>
{
	public:
		IntakeSubsystem();

		enum Position
		{
			EXTEND,
			RETRACT,
		};

		void IntakeSetSpeed(float speed);
		void IntakeSetPosition(Position current);
		void IntakeInit();

	private:
		Talon m_IntakeTalon;
		Relay m_IntakeRelay;

};
