#pragma once
#include <WPILib.h>
#include "../Robotmap.h"
#include "SafeButton.h"
#include "Joystick.h"

/**
* @brief This class is the driver for the Logitech
* Attack 3 Joystick. This joystick is often used at
* competition to control the robot. This joystick
* is not deadband adjusted, as these joysticks do
* not seem to need deadband calibration.
*
* This class also contains JoystickButtons for all of the
* buttons that are available on the XBox joystick itself.
* These buttons can be assigned by calling
* <code>[stick].[button].WhenPressed()</code>.
*
* @author Arthur Lockman
*/

class Attack3Joystick: public Joystick
{
	public:
		Attack3Joystick(int port);
		float GetStickX();
		float GetStickY();
		float GetStickZ();
		float GetPOT();
		bool GetTrigger();
		bool GetButton2();
		bool GetButton3();
		bool GetButton4();
		bool GetButton5();
		bool GetButton6();
		bool GetButton7();
		bool GetButton8();
		bool GetButton9();
		bool GetButton10();
		bool GetButton11();
		bool GetButton12();
		SafeButton Trigger;
		SafeButton Button2;
		SafeButton Button3;
		SafeButton Button4;
		SafeButton Button5;
		SafeButton Button6;
		SafeButton Button7;
		SafeButton Button8;
		SafeButton Button9;
		SafeButton Button10;
		SafeButton Button11;
		SafeButton Button12;

	private:
		float Deadband(float input);
};


