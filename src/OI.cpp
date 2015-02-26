#include "OI.h"
#include "Commands/SetDriveMode.hpp"
#include "Commands/SetIntakeMode.hpp"
#include "Commands/ExpelStack.hpp"
#include "Commands/ConsumeTote.hpp"
#include "Commands/DropTote.hpp"
#include "Commands/OrientBin.hpp"
#include "Commands/HoldBin.hpp"

OI::OI() :
	m_DriverStick(kDriverStickPort),
	m_ManipulatorStick(kManipulatorStickPort) {}

void OI::init()
{
	// Process operator interface input here.
    m_DriverStick.RightBumper.WhenPressed<SetDriveMode<ENCODERS_ON> >();
    m_DriverStick.LeftBumper.WhenPressed<SetDriveMode<ENCODERS_OFF> >();
    m_DriverStick.X.WhenPressed<SetDriveMode<MAJOR_AXIS_ONLY> >();
    m_DriverStick.Y.WhenPressed<SetDriveMode<BOTH_AXES> >();

    m_DriverStick.A.WhenPressed<SetIntakeMode<REVERSE> >();
    m_DriverStick.B.WhenPressed<SetIntakeMode<FORWARD> >();
    m_DriverStick.Start.WhenPressed<SetIntakeMode<STOPPED> >();

    m_ManipulatorStick.Button2.WhenPressed<ExpelStack>();
    m_ManipulatorStick.Button3.WhileHeld<ConsumeTote>();
    m_ManipulatorStick.Button4.WhileHeld<DropTote>();
    m_ManipulatorStick.Button5.WhenPressed<OrientBin>();
    m_ManipulatorStick.Button6.WhileHeld<HoldBin>();

    m_ManipulatorStick.Button7.WhenPressed<SetIntakeMode<REVERSE> >();
    m_ManipulatorStick.Button8.WhenPressed<SetIntakeMode<FORWARD> >();
    m_ManipulatorStick.Button9.WhenPressed<SetIntakeMode<STOPPED> >();
}

FRCXboxJoystick& OI::GetDriverStick()
{
    return m_DriverStick;
}

Attack3Joystick& OI::GetManipulatorStick()
{
	return m_ManipulatorStick;
}
