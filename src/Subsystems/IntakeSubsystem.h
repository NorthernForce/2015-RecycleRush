#pragma once

#include "WPILib.h"
#include "SubsystemWithCommand.hpp"

class IntakeSubsystem : public Subsystem
{
	public:
		IntakeSubsystem();

		void SetIntakeSpeed(float speed);
		void SetReverseIntakeSpeed(float speed);
		void GetIntakeSpeed();
		void init();

	private:
		Talon		m_IntakeRight;
		Talon    	m_IntakeLeft;
};
