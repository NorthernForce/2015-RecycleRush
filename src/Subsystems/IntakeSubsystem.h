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
		Talon		m_IntakeRight;
		Talon 		m_IntakeLeft;
};
