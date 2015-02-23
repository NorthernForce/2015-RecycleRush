#pragma once

#include "WPILib.h"
#include "Lib/FRCXboxJoystick.h"
#include "Lib/Attack3Joystick.h"

class OI {
private:
    FRCXboxJoystick m_DriverStick;
    Attack3Joystick m_ManipulatorStick;
public:
	OI();
	void init();
    FRCXboxJoystick& GetDriverStick();
    Attack3Joystick& GetManipulatorStick();
};
