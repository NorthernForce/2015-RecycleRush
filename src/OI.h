#pragma once

#include "WPILib.h"
#include "Lib/FRCXboxJoystick.h"
#include "Lib/Attack3Joystick.h"

class OI
{
	public:
		OI();
		void init();
		FRCXboxJoystick& GetDriverStick();
		Attack3Joystick& GetManipulatorStick();
		FRCXboxJoystick& GetXBoxManipulatorStick();

	private:
		FRCXboxJoystick m_DriverStick;
		Attack3Joystick m_ManipulatorStick;
		FRCXboxJoystick m_XBoxManipulatorStick;

};
