#include "LimitSwitch.h"
#include "../RobotMap.h"

LimitSwitch::LimitSwitch():

SubsystemWithCommand<void>("LimitSwitch"),
m_totelimitswitch (1),
m_binlimitswitch (2),
m_pickuplimitswitch (3),
m_scoringlimitswitch (4) {}

void LimitSwitch::isSwitchSet (uint32_t channel)
{
	switch (channel)
	{
		case (1):
		m_totelimitswitch.Get();
		break;

		case (2):
		m_binlimitswitch.Get();
		break;

		case (3):
		m_pickuplimitswitch.Get();
		break;

		case (4):
		m_scoringlimitswitch.Get();
		break;

		default:
		break;
	}
}
