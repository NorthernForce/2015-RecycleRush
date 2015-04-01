#pragma once
//#include "Commands/Subsystem.h"
#include "WPILib.h"
#include "SubsystemWithCommand.hpp"
#include "../Commands/DriveWithJoystick.h"

class MecanumDrive: public SubsystemWithCommand<DriveWithJoystick>
{
	public:
		MecanumDrive();
		void DriveMecanum(float xVel, float yVel, float rotVel);
		void EnableEncoders(bool invertGains = true);
		void DisableEncoders();
		void SetMajorAxisMode(bool on);
		void init();

		double P;// = 1.25;
		double I;// = 0.02;
		double D;// = 0.00;
		int n;

	private:
		bool m_majorAxisMode;
		int frontLeft_alive;
		int frontRight_alive;
		int backLeft_alive;
		int backRight_alive;
		CANTalon m_frontLeft;
		CANTalon m_frontRight;
		CANTalon m_backLeft;
		CANTalon m_backRight;
		RobotDrive m_drive;
};
