#include "MecanumDrive.h"
#include <cmath>
#include "../Commands/DriveWithJoystick.h"
#include "../Robotmap.h"

MecanumDrive::MecanumDrive() try :
	SubsystemWithCommand<DriveWithJoystick>("MecanumDrive"),
	P(0.50),
	I(0.02),
	D(0.00),
	n(0),
	m_majorAxisMode(true),
	frontLeft_alive(true),
	frontRight_alive(true),
	backLeft_alive(true),
	backRight_alive(true),
    m_frontLeft(kFrontLeftTalon),
    m_frontRight(kFrontRightTalon),
    m_backLeft(kBackLeftTalon),
    m_backRight(kBackRightTalon),
    m_drive(m_frontLeft, m_backLeft, m_frontRight, m_backRight)
{
	m_drive.SetSafetyEnabled(false);
}
catch (...)
{
	std::cout << "Exception caught in MecanumDrive::MecanumDrive\n"; //<< e.what() << std::endl;
}

void MecanumDrive::init()
{
	m_drive.SetSafetyEnabled(false);
	// Invert the left motors.
	m_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);  //PRACTICE ROBOT
	m_drive.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	m_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor,  false);
	m_drive.SetInvertedMotor(RobotDrive::kRearRightMotor,  true);

	/*m_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, true);  //COMPETITION ROBOT: Wired 180 degrees different, FL = RR, etc.
	m_drive.SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
	m_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor,  true);
	m_drive.SetInvertedMotor(RobotDrive::kRearRightMotor,  false);*/

	// Make sure the timeout is reasonable
	m_drive.SetExpiration(0.2);

	// By default enable encoders. Either this function
	// or DisableEncoders() should be called, otherwise
	// the motors are not properly inverted, or set up.
	//EnableEncoders();
	DisableEncoders();
}

void MecanumDrive::EnableEncoders(bool invertGains)
{
	// When encoders are enabled, all motors must be inverted from
	// what they normaly would be.
	m_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor, false);
	m_drive.SetInvertedMotor(RobotDrive::kFrontRightMotor, true);
	m_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor,  false);
	m_drive.SetInvertedMotor(RobotDrive::kRearRightMotor,  true);
	// Set max output to be max drive rpm, since the Talons read
	// the encoder speed in rpm.
	m_drive.SetMaxOutput(kMaxDriveRPM);

	// Disable encoders, if alread enabled.
	// Not sure this is necessary.
	m_frontLeft.Disable();
	m_backLeft.Disable();
	m_frontRight.Disable();
	m_backRight.Disable();

	// Max voltage should be 12V (Robot has 12V battery).
	m_frontLeft.ConfigMaxOutputVoltage(kMaxDriveVoltage);
	m_backLeft.ConfigMaxOutputVoltage(kMaxDriveVoltage);
	m_frontRight.ConfigMaxOutputVoltage(kMaxDriveVoltage);
	m_backRight.ConfigMaxOutputVoltage(kMaxDriveVoltage);

	// To use the encoders, we need to be in either
	// speed mode or position mode. For driving the
	// robot, speed mode makes more sense.
	m_frontLeft.SetControlMode(CANTalon::kSpeed);
	m_frontLeft.Set(10.0);
	m_backLeft.SetControlMode(CANTalon::kSpeed);
	m_backLeft.Set(10.0);
	m_frontRight.SetControlMode(CANTalon::kSpeed);
	m_frontRight.Set(10.0);
	m_backRight.SetControlMode(CANTalon::kSpeed);
	m_backRight.Set(10.0);

	// Fetch PID gains from the smart dashboard.
	P = SmartDashboard::GetNumber("Drive P");
	I = SmartDashboard::GetNumber("Drive I");
	D = SmartDashboard::GetNumber("Drive D");

	// Set proportional, integral and derivative gains,
	// inverting if appropriate.
	if(invertGains)
	{
		m_frontLeft.SetPID(-P, -I, -D);
		m_backLeft.SetPID(-P, -I, -D);
		m_frontRight.SetPID(-P, -I, -D);
		m_backRight.SetPID(-P, -I, -D);
	}
	else
	{
		m_frontLeft.SetPID(P, I, D);
		m_backLeft.SetPID(P, I, D);
		m_frontRight.SetPID(P, I, D);
		m_backRight.SetPID(P, I, D);
	}

	// We have quadrature encoders
	m_frontLeft.SetFeedbackDevice(CANTalon::QuadEncoder);
	m_backLeft.SetFeedbackDevice(CANTalon::QuadEncoder);
	m_frontRight.SetFeedbackDevice(CANTalon::QuadEncoder);
	m_backRight.SetFeedbackDevice(CANTalon::QuadEncoder);

	// Set encoder pulses per rev
	m_frontLeft.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
	m_backLeft.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
	m_frontRight.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);
	m_backRight.ConfigEncoderCodesPerRev(kEncoderPulsesPerRev);

	// Enable encoder control with the parameters above.
	m_frontLeft.EnableControl();
	m_backLeft.EnableControl();
	m_frontRight.EnableControl();
	m_backRight.EnableControl();
}

void MecanumDrive::DisableEncoders()
{
	// Motors have to be inverted for using encoders, so they have
	// to be set back for kPercentVbus mode.
	m_drive.SetInvertedMotor(RobotDrive::kFrontLeftMotor,   true);
	m_drive.SetInvertedMotor(RobotDrive::kFrontRightMotor, false);
	m_drive.SetInvertedMotor(RobotDrive::kRearLeftMotor,    true);
	m_drive.SetInvertedMotor(RobotDrive::kRearRightMotor,  false);

	// Output values for kPercentVbus mode are -1..1, so
	// max output should be 1.0
	m_drive.SetMaxOutput(1.0);

	// Change mode to kPercentVbus.
	m_frontLeft.SetControlMode(CANTalon::kPercentVbus);
	m_backLeft.SetControlMode(CANTalon::kPercentVbus);
	m_frontRight.SetControlMode(CANTalon::kPercentVbus);
	m_backRight.SetControlMode(CANTalon::kPercentVbus);

	// Enable the talons
	m_frontLeft.EnableControl();
	m_backLeft.EnableControl();
	m_frontRight.EnableControl();
	m_backRight.EnableControl();
}

void MecanumDrive::SetMajorAxisMode(bool on) {
	m_majorAxisMode = on;
}

void MecanumDrive::DriveMecanum(float xVel, float yVel, float rotVel)
{
	if(m_majorAxisMode) {
		if (fabs(xVel) > fabs(yVel))
			yVel = 0.0f;
		else
			xVel = 0.0f;
	}


	// Drive Mecanum
	m_drive.MecanumDrive_Cartesian(xVel, yVel, rotVel);

	// Update smart dashboard with command, output voltage,
	// registered output, and input voltage, for each Talon.
	// Only do this 5 times a second.


	n++;
	if(n%10 == 0)
	{
		if (m_frontLeft.IsAlive())// || m_frontLeft.GetPowerCycled())
		{
			frontLeft_alive = 10;
		}

		if(m_frontRight.IsAlive())// || m_frontRight.GetPowerCycled())
	    {
			frontRight_alive = 10;
		}

		if(m_backLeft.IsAlive())// || m_backLeft.GetPowerCycled())
		{
			backLeft_alive = 10;
		}

		if(m_backRight.IsAlive())// || m_backRight.GetPowerCycled())
		{
			backRight_alive = 10;
		}

		if(frontLeft_alive > 0) --frontLeft_alive;
		if(frontRight_alive > 0) --frontRight_alive;
		if(backLeft_alive > 0) --backLeft_alive;
		if(backRight_alive > 0) --backRight_alive;

		SmartDashboard::PutNumber("M4 Command", m_frontLeft.Get());
		SmartDashboard::PutNumber("M4 Output",  m_frontLeft.GetSpeed());
		SmartDashboard::PutNumber("M4 Voltage", m_frontLeft.GetOutputVoltage());
		SmartDashboard::PutNumber("M4 VBus", m_frontLeft.GetBusVoltage());
		SmartDashboard::PutBoolean("M4 Alive",  frontLeft_alive == 0);

		SmartDashboard::PutNumber("M2 Command", m_frontRight.Get());
		SmartDashboard::PutNumber("M2 Output",  m_frontRight.GetSpeed());
		SmartDashboard::PutNumber("M2 Voltage", m_frontRight.GetOutputVoltage());
		SmartDashboard::PutNumber("M2 VBus", m_frontRight.GetBusVoltage());
		SmartDashboard::PutBoolean("M2 Alive",  frontRight_alive == 0);

		SmartDashboard::PutNumber("M3 Command", m_backLeft.Get());
		SmartDashboard::PutNumber("M3 Output",  m_backLeft.GetSpeed());
		SmartDashboard::PutNumber("M3 Voltage", m_backLeft.GetOutputVoltage());
		SmartDashboard::PutNumber("M3 VBus", m_backLeft.GetBusVoltage());
		SmartDashboard::PutBoolean("M3 Alive",  backLeft_alive == 0);

		SmartDashboard::PutNumber("M1 Command", m_backRight.Get());
		SmartDashboard::PutNumber("M1 Output",  m_backRight.GetSpeed());
		SmartDashboard::PutNumber("M1 Voltage", m_backRight.GetOutputVoltage());
		SmartDashboard::PutNumber("M1 VBus", m_backRight.GetBusVoltage());
		SmartDashboard::PutBoolean("M1 Alive",  backRight_alive == 0);
	}
}
