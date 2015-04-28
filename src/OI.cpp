#include "OI.h"
#include "Commands/SetDriveMode.hpp"
#include "Commands/SetIntakeMode.hpp"
#include "Commands/SetBinMode.hpp"
#include "Commands/SetLifterMode.hpp"
#include "Commands/SetWheelMode.hpp"
#include "Commands/SetWedgeMode.hpp"


OI::OI() :
    m_DriverStick(kDriverStickPort),
    m_ManipulatorStick(kManipulatorStickPort)
	//m_XBoxManipulatorStick(kXBoxManipulatorPort)
	{}


void OI::init()
{
	// Process operator interface input here.
    m_DriverStick.RightBumper.WhenPressed<SetDriveMode<ENCODERS_ON> >();
    m_DriverStick.LeftBumper.WhenPressed<SetDriveMode<ENCODERS_OFF> >();
    m_DriverStick.X.WhenPressed<SetDriveMode<MAJOR_AXIS_ONLY> >();
    m_DriverStick.Y.WhenPressed<SetDriveMode<BOTH_AXES> >();

    //m_DriverStick.A.WhenPressed<SetBinMode<IN> >();
    //m_DriverStick.B.WhenPressed<SetBinMode<OUT> >();
    m_DriverStick.Start.WhenPressed<SetIntakeMode<STOPPED> >();


    //m_ManipulatorStick.Button4.ToggleWhenPressed<ConsumeTote>(); 				// actually 3
    //m_ManipulatorStick.Button4.ToggleWhenPressed<DropTote>(); 			    // actually 3
    //m_ManipulatorStick.Button3.ToggleWhenPressed<OrientBin>(); 				// actually 2
    //m_ManipulatorStick.Button3.ToggleWhenPressed<ReOrientBin>();				// actually 2
    m_ManipulatorStick.Button4.WhenPressed<SetLifterMode<DOWN>            >();	// actually 3
    m_ManipulatorStick.Button3.WhenPressed<SetLifterMode<UP>              >();  // actually 2



    m_ManipulatorStick.Button5.ToggleWhenPressed<SetIntakeMode<FORWARD>   >(); 	// actually 4
    m_ManipulatorStick.Button5.ToggleWhenPressed<SetIntakeMode<STOPPED>   >(); 	// actually 4
    m_ManipulatorStick.Button6.ToggleWhenPressed<SetIntakeMode<REVERSE>   >(); 	// actually 5
    m_ManipulatorStick.Button6.ToggleWhenPressed<SetIntakeMode<STOPPED>   >(); 	// actually 5
    m_ManipulatorStick.Button7.ToggleWhenPressed<SetIntakeMode<OPPOSITE1> >();  // actually 6
    m_ManipulatorStick.Button7.ToggleWhenPressed<SetIntakeMode<STOPPED>   >(); 	// actually 6
    m_ManipulatorStick.Button8.ToggleWhenPressed<SetIntakeMode<OPPOSITE2> >();  // actually 7
    m_ManipulatorStick.Button8.ToggleWhenPressed<SetIntakeMode<STOPPED>   >(); 	// actually 7


    //m_ManipulatorStick.Button2.ToggleWhenPressed<ActuateWheels<IN>      >();  // actually 1
    //m_ManipulatorStick.Button2.ToggleWhenPressed<ActuateWheels<OUT>     >();	// actually 1
    m_ManipulatorStick.Button2.WhenPressed<SetWheelMode<ACTUATE>            >();
    m_ManipulatorStick.Button2.WhenReleased<SetWheelMode<UNACTUATE>       >();

    m_ManipulatorStick.Button9.ToggleWhenPressed<SetBinMode<IN>           >();					// actually 8
    m_ManipulatorStick.Button9.ToggleWhenPressed<SetBinMode<OUT>          >();					// actually 8
    m_ManipulatorStick.Button10.ToggleWhenPressed<SetWedgeMode<ACTUATED>>();
    m_ManipulatorStick.Button10.ToggleWhenPressed<SetWedgeMode<UNACTUATED>>();


    /*m_XBoxManipulatorStick.A.ToggleWhenPressed<SetLifterMode <UP>>();
    m_XBoxManipulatorStick.A.ToggleWhenPressed<SetLifterMode <DOWN>>();
    m_XBoxManipulatorStick.B.WhenPressed<SetWheelMode<ACTUATE> >();
    m_XBoxManipulatorStick.X.WhenPressed<SetWheelMode<UNACTUATE> >();
    m_XBoxManipulatorStick.Y.ToggleWhenPressed<SetBinMode<IN>>();
    m_XBoxManipulatorStick.Y.ToggleWhenPressed<SetBinMode<OUT>>();
    m_XBoxManipulatorStick.RightBumper.WhenPressed<SetIntakeMode<OPPOSITE1> >();
    m_XBoxManipulatorStick.LeftBumper.WhenPressed<SetIntakeMode<OPPOSITE2> >();*/





}

FRCXboxJoystick& OI::GetDriverStick()
{
    return m_DriverStick;
}


Attack3Joystick& OI::GetManipulatorStick()
{
	return m_ManipulatorStick;
}


/*FRCXboxJoystick& OI::GetXBoxManipulatorStick()
{
	return m_XBoxManipulatorStick;
}*/
