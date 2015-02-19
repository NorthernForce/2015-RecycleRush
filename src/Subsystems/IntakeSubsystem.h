#pragma once

#include "WPILib.h"
#include "SubsystemWithCommand.hpp"

class IntakeSubsystem : public Subsystem
{
	public:
		IntakeSubsystem();

		void SetIntakeSpeed(float speed);
		//void IntakeSetPosition(IntakeMode m_mode);
		void IntakeInit();

	private:
		PWM m_IntakeRight;
		PWM m_IntakeLeft;
		//Relay m_IntakeRelay;
};
