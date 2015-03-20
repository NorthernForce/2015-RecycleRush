#pragma once
#include <WPILib.h>
#include "../Robotmap.h"
#include "Joystick.h"
#include "SafeButton.h"
/*
 * @brief This class is the driver for the XBox Joystick
 * that we use at competition to control the robot.
 * All of the values returned by this class are
 * already adjusted for the deadband in the controller itself.
 *
 * This class also contains JoystickButtons for all of the
 * buttons that are available on the XBox joystick itself.
 * These buttons can be assigned by calling [stick].[button].WhenPressed().
 *
 * @author Arthur Lockman
 */
class FRCXboxJoystick: public Joystick
{
	public:
		FRCXboxJoystick(int port);
		FRCXboxJoystick(const FRCXboxJoystick& other) :
		  Joystick(other.m_port),
		  A(other.A),
		  B(other.B),
		  X(other.X),
		  Y(other.Y),
		  Back(other.Back),
		  Start(other.Start),
		  LeftBumper(other.LeftBumper),
		  RightBumper(other.RightBumper),
		  Deadband(other.Deadband),
		  m_port(other.m_port)
		{}
		virtual ~FRCXboxJoystick() {}

		float GetLeftStickY();
		float GetLeftStickX();
		float GetRightStickY();
		float GetRightStickX();
		float GetRightTrigger();
		float GetLeftTrigger();

		bool GetAButton();
		bool GetBButton();
		bool GetXButton();
		bool GetYButton();
		bool GetStartButton();
		bool GetBackButton();
		bool GetLeftBumper();
		bool GetRightBumper();

		SafeButton A;
		SafeButton B;
		SafeButton X;
		SafeButton Y;
		SafeButton Back;
		SafeButton Start;
		SafeButton LeftBumper;
		SafeButton RightBumper;

	private:
		void CalculateDeadband();
		float DeadbandAdjust(float);
		virtual float GetX(JoystickHand);
		virtual float GetY(JoystickHand);

		virtual float GetZ() { return 0.0;}
		virtual float GetTwist() { return 0.0; }
		virtual float GetThrottle() { return 0.0; }
		virtual float GetRawAxis(uint32_t axis) { return 1.0; }

		virtual bool GetTrigger(JoystickHand hand = kRightHand) { return false; }
		virtual bool GetTop(JoystickHand hand = kRightHand)  { return false; }
		virtual bool GetBumper(JoystickHand hand = kRightHand)  { return false; }
		virtual bool GetRawButton(uint32_t button)  { return false; }
		virtual int GetPOV(uint32_t pov = 0)  { return 0; }

	private:
		float Deadband;
		int m_port;
};
