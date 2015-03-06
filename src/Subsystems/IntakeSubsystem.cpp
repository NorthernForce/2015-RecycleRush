#include "IntakeSubsystem.h"
#include "../RobotMap.h"


IntakeSubsystem::IntakeSubsystem() :
	Subsystem("IntakeSubsystem"),
	m_IntakeRight(kIntakeRight),
	m_IntakeLeft(kIntakeLeft)

{
	m_IntakeRight.SetSpeed(0.0);
	m_IntakeLeft.SetSpeed(0.0);
}

void IntakeSubsystem::SetIntakeSpeed(float speed)
{
	m_IntakeRight.SetSpeed(speed);
	m_IntakeLeft.SetSpeed(-speed);
}


void IntakeSubsystem::GetIntakeSpeed()
{
	float rightIntakeSpeed = m_IntakeRight.Get();
	float leftIntakeSpeed = m_IntakeLeft.Get();

	SmartDashboard::PutNumber("Right Intake Speed: ", rightIntakeSpeed);
	SmartDashboard::PutNumber("Left Intake Speed: ", leftIntakeSpeed);

}

void IntakeSubsystem::init()
{
	m_IntakeRight.SetSpeed(0.0);
	m_IntakeLeft.SetSpeed(0.0);
}
