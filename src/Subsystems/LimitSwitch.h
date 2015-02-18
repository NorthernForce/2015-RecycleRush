#pragma once

#include "WPILib.h"
#include "SubsystemWithCommand.hpp"

class LimitSwitch : public SubsystemWithCommand<void>
{
	public:
		LimitSwitch();
		void isSwitchSet(uint32_t channel);

	private:
		DigitalInput	m_totelimitswitch;
		DigitalInput	m_binlimitswitch;
		DigitalInput	m_pickuplimitswitch;
		DigitalInput	m_scoringlimitswitch;
};
