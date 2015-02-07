#pragma once

#include "WPILib.h"
#include "Lib/FRCXboxJoystick.h"

class OI {
private:
    FRCXboxJoystick m_DriverStick;
public:
	OI();
	void init();
    FRCXboxJoystick& GetDriverStick();
};
