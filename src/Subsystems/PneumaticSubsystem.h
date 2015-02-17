#pragma once

#include "WPIlib.h"
#include "SubsystemWithCommand.hpp"

class PneumaticSubsystem : public SubsystemWithCommand <void>
{
	public:
	private:
		Solenoid m_Solenoid;
		DoubleSolenoid m_DSolenoid;
};

