#include "OI.h"
#include "Commands/SetDriveMode.hpp"
#include "Commands/SetIntakeMode.hpp"
#include "Commands/ExpelStack.hpp"
#include "Commands/ConsumeTote.hpp"
#include "Commands/DropTote.hpp"
#include "Commands/OrientBin.hpp"
#include "Commands/HoldBin.hpp"
#include "Commands/ReleaseBin.hpp"
#include "Commands/ReOrientBin.hpp"

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


    m_ManipulatorStick.Button4.ToggleWhenPressed<ConsumeTote>(); 				// actually 3
    m_ManipulatorStick.Button4.ToggleWhenPressed<DropTote>(); 				    // actually 3
    m_ManipulatorStick.Button2.ToggleWhenPressed<OrientBin>(); 					// actually 1
    m_ManipulatorStick.Button2.ToggleWhenPressed<ReOrientBin>();				// actually 1

    m_ManipulatorStick.Button6.ToggleWhenPressed<SetIntakeMode<REVERSE> >(); 	// actually 4
    m_ManipulatorStick.Button6.ToggleWhenPressed<SetIntakeMode<STOPPED> >(); 	// actually 4
    m_ManipulatorStick.Button5.ToggleWhenPressed<SetIntakeMode<FORWARD> >(); 	// actually 5
    m_ManipulatorStick.Button5.ToggleWhenPressed<SetIntakeMode<STOPPED> >(); 	// actually 5

    m_ManipulatorStick.Button3.ToggleWhenPressed<HoldBin>(); 					// actually 2
    m_ManipulatorStick.Button3.ToggleWhenPressed<ReleaseBin>();					// actually 2

    m_ManipulatorStick.Button10.WhenPressed<ExpelStack>();						// actually 9


}

FRCXboxJoystick& OI::GetDriverStick()
{
    return m_DriverStick;
}

Attack3Joystick& OI::GetManipulatorStick()
{
	return m_ManipulatorStick;
}
