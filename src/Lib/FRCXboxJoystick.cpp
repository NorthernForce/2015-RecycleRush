#include "FRCXboxJoystick.h"
#include "Joystick.h"
#include <math.h>

/**
 * @brief This class constructs the instance
 * of the XBox Joystick. It automatically
 * calculates the deadband for the joysticks
 * on the controller.
 *
 * @author Arthur Lockman
 */
FRCXboxJoystick::FRCXboxJoystick(int port):
	Joystick(port),
     A(this, kXBoxButtonA),
     B(this, kXBoxButtonB),
     X(this, kXBoxButtonX),
     Y(this, kXBoxButtonY),
     Back(this, kXBoxButtonBack),
     Start(this, kXBoxButtonStart),
     LeftBumper(this, kXBoxButtonLeft),
     RightBumper(this, kXBoxButtonRight),
	 Deadband(0.0),
	 m_port(port)
{
 	CalculateDeadband();
}

/**
 * @brief Gets the value from the X axis
 * of one of the joysticks on the controller.
 *
 * @param hand The joystick hand to get,
 * kLeftHand or kRightHand.
 *
 * @return A float of the value of the
 * X axis of the joystick.
 *
 * @author Joseph Martin
 */
float FRCXboxJoystick::GetX(JoystickHand hand)
{
	return DeadbandAdjust(Joystick::GetX(hand));
}

/**
 * @brief Gets the value from the Y axis
 * of one of the joysticks on the controller.
 *
 * @param hand The joystick hand to get,
 * kLeftHand or kRightHand.
 *
 * @return A float of the value of the
 * Y axis of the joystick.
 *
 * @author Joseph Martin
 */
float FRCXboxJoystick::GetY(JoystickHand hand)
{
	return DeadbandAdjust(Joystick::GetY(hand));
}

void FRCXboxJoystick::CalculateDeadband()
{
    Deadband = 0.1; //0.025; //0.2;
}

/**
 * @brief Calculates the value that the controller
 * should be returning based on the calculated
 * deadband value.
 *
 * @param val The value to apply the deadband
 * calculations to.
 *
 * @return A float, the calculated value.
 *
 * @author Arthur Lockman
 */
float FRCXboxJoystick::DeadbandAdjust(float val)
{
	float adjusted = val < Deadband && val > (-1 * Deadband)
	 ? 0.0
	 : (val-(fabs(val) / val * Deadband)) / (1 - Deadband);
	return adjusted;
}

/**
 * @brief Gets the Y of the left stick on the controller.
 * @return the value of the Y axis, adjusted for the controller deadband.
 */
float FRCXboxJoystick::GetLeftStickY()
{
	float value = Joystick::GetRawAxis(1); // was 2
	value = DeadbandAdjust(value);
	return -value;
}

/**
 * @brief Gets the X of the left stick on the controller.
 * @return the value of the X axis, adjusted for the controller deadband.
 */
float FRCXboxJoystick::GetLeftStickX()
{
	float value = Joystick::GetRawAxis(0); // was 1
	return -DeadbandAdjust(value);
}

/**
 * @brief Gets the Y of the right stick on the controller.
 * @return the value of the Y axis, adjusted for the controller deadband.
 */
float FRCXboxJoystick::GetRightStickY()
{
	float value = DeadbandAdjust(Joystick::GetRawAxis(5));
	return -value;
}

/**
 * @brief Gets the X of the right stick on the controller.
 * @return the value of the Y axis, adjusted for the controller deadband.
 */
float FRCXboxJoystick::GetRightStickX()
{
	float value = DeadbandAdjust(Joystick::GetRawAxis(4));
	return -value;
}

/**
 * @brief Gets the value of the trigger on the controller.
 * This value accounts for both triggers, so use it wisely.
 * @return The value of the trigger, not adjusted for the deadband.
 */
float FRCXboxJoystick::GetTrigger()
{
	float value = Joystick::GetRawAxis(3);
	return -value;
}

/**
 * @brief Returns the same as A.Get(), but is here for convenience.
 * @return The button state.
 */
bool FRCXboxJoystick::GetAButton()
{
	return A.Get();
}

/**
 * @brief Returns the same as B.Get(), but is here for convenience.
 * @return The button state.
 */
bool FRCXboxJoystick::GetBButton()
{
	return B.Get();
}

/**
 * @brief Returns the same as X.Get(), but is here for convenience.
 * @return The button state.
 */
bool FRCXboxJoystick::GetXButton()
{
	return X.Get();
}

/**
 * @brief Returns the same as Y.Get(), but is here for convenience.
 * @return The button state.
 */
bool FRCXboxJoystick::GetYButton()
{
	return Y.Get();
}

/**
 * @brief Returns the same as Start.Get(), but is here for convenience.
 * @return The button state.
 */
bool FRCXboxJoystick::GetStartButton()
{
	return Start.Get();
}

/**
 * @brief Returns the same as Back.Get(), but is here for convenience.
 * @return The button state.
 */
bool FRCXboxJoystick::GetBackButton()
{
	return Back.Get();
}

/**
 * @brief Returns the same as LeftBumper.Get(), but is here for convenience.
 * @return The button state.
 */
bool FRCXboxJoystick::GetLeftBumper()
{
	return LeftBumper.Get();
}

/**
 * @brief Returns the same as RightBumper.Get(), but is here for convenience.
 * @return The button state.
 */
bool FRCXboxJoystick::GetRightBumper()
{
	return RightBumper.Get();
}

