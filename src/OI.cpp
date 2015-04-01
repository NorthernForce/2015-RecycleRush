#include "OI.h"
#include "Commands/SetDriveMode.hpp"
#include "Commands/SetIntakeMode.hpp"
#include "Commands/SetLifterMode.hpp"
#include "Commands/SetBinOrienterMode.hpp"
#include "Commands/SeBinMode.hpp"
#include "Commands/SetWheelMode.hpp"


OI::OI() :
	m_DriverStick(kDriverStickPort),
	m_ManipulatorStick(kManipulatorStickPort) {}

void OI::init()
{
    m_DriverStick.RightBumper.WhenPressed<SetDriveMode<ENCODERS_ON> >();
    m_DriverStick.LeftBumper.WhenPressed<SetDriveMode<ENCODERS_OFF> >();
    m_DriverStick.X.WhenPressed<SetDriveMode<MAJOR_AXIS_ONLY> >();
    m_DriverStick.Y.WhenPressed<SetDriveMode<BOTH_AXES> >();

    m_DriverStick.A.WhenPressed<SetIntakeMode<REVERSE> >();
    m_DriverStick.B.WhenPressed<SetIntakeMode<FORWARD> >();
    m_DriverStick.Start.WhenPressed<SetIntakeMode<STOPPED> >();

    m_ManipulatorStick.Button4.ToggleWhenPressed<SetLifterMode<UP>        >();  // actually 3
    m_ManipulatorStick.Button4.ToggleWhenPressed<SetLifterMode<DOWN>      >(); 	// actually 3
    m_ManipulatorStick.Button3.ToggleWhenPressed<SetBinMode<IN>           >(); 	// actually 2
    m_ManipulatorStick.Button3.ToggleWhenPressed<SetBinMode<OUT>          >();	// actually 2

    m_ManipulatorStick.Button5.ToggleWhenPressed<SetIntakeMode<FORWARD>   >(); 	// actually 4
    m_ManipulatorStick.Button5.ToggleWhenPressed<SetIntakeMode<STOPPED>   >(); 	// actually 4
    m_ManipulatorStick.Button6.ToggleWhenPressed<SetIntakeMode<REVERSE>   >(); 	// actually 5
    m_ManipulatorStick.Button6.ToggleWhenPressed<SetIntakeMode<STOPPED>   >(); 	// actually 5
    m_ManipulatorStick.Button7.ToggleWhenPressed<SetIntakeMode<OPPOSITE1> >();  // actually 6
    m_ManipulatorStick.Button7.ToggleWhenPressed<SetIntakeMode<STOPPED>   >(); 	// actually 6
    m_ManipulatorStick.Button8.ToggleWhenPressed<SetIntakeMode<OPPOSITE2> >();  // actually 7
    m_ManipulatorStick.Button8.ToggleWhenPressed<SetIntakeMode<STOPPED>   >(); 	// actually 7

    m_ManipulatorStick.Button2.ToggleWhileHeld<SetWheelMode<IN>           >();  // actually 1
    m_ManipulatorStick.Button2.ToggleWhileHeld<SetWheelMode<OUT>          >();	// actually 1

    m_ManipulatorStick.Button9.ToggleWhenPressed<SetBinMode<IN>           >();	// actually 8
    m_ManipulatorStick.Button9.ToggleWhenPressed<SetBinMode<OUT>          >();	// actually 8


}

FRCXboxJoystick& OI::GetDriverStick()
{
    return m_DriverStick;
}

Attack3Joystick& OI::GetManipulatorStick()
{
	return m_ManipulatorStick;
}
