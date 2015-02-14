#include "IntakeSubsystem.h"
#include "../RobotMap.h"


IntakeSubsystem::IntakeSubsystem() :

	Subsystem("IntakeSubsystem"),
	m_IntakeTalon(kIntakeTalon)
	//m_IntakeRelay(kIntakeRelay, Relay::kBothDirections)
{
	//m_IntakeRelay.Set(Relay::kReverse);
}

void IntakeSubsystem::SetIntakeSpeed(float speed)
{
	m_IntakeTalon.Set(-speed);
}

/*
void IntakeSubsystem::IntakeSetPosition(IntakeMode m_mode)
{
	switch(IntakeMode m_mode)
	{
		case FORWARD:
			m_IntakeRelay.Set(Relay::kForward);
			break;
		case REVERSE:
			m_IntakeRelay.Set(Relay::kReverse);
			break;
	}
}
*/

void IntakeSubsystem::IntakeInit()
{

}
