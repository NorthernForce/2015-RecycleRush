#include "IntakeSubsystem.h"
#include "../RobotMap.h"


IntakeSubsystem::IntakeSubsystem() :

	SubsystemWithCommand<void>("IntakeSubsystem"),
	m_IntakeTalon(kIntakeTalon),
	m_IntakeRelay(kIntakeRelay, Relay::kBothDirections)
{
	m_IntakeRelay.Set(Relay::kReverse);
}

void IntakeSubsystem::IntakeSetSpeed(float speed)
{
	m_IntakeTalon.Set(-speed);
}

void IntakeSubsystem::IntakeSetPosition(Position current)
{
	switch(current)
	{
		case EXTEND:
			m_IntakeRelay.Set(Relay::kReverse);
			break;
		case RETRACT:
			m_IntakeRelay.Set(Relay::kForward);
			break;
	}
}

void IntakeSubsystem::IntakeInit()
{

}
