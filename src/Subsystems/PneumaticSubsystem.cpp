#include "PneumaticSubsystem.h"
#include "../RobotMap.h"


PneumaticSubsystem::PneumaticSubsystem():
		SubsystemWithCommand<void>("PneumaticSubsystem"),
		m_BinOrienter(kSolenoidPort1, kSolenoidPort2),
		m_BinHolder(kSolenoidPort3, kSolenoidPort4),
		m_ToteLifter(kSolenoidPort5, kSolenoidPort6)
		{}


void PneumaticSubsystem::SetBinOrienter()
{
	m_BinOrienter.Set(DoubleSolenoid::kForward);
}

void PneumaticSubsystem::ResetBinOrienter()
{
	m_BinOrienter.Set(DoubleSolenoid::kReverse);
}

void PneumaticSubsystem::SetBinHolder()
{
	m_BinHolder.Set(DoubleSolenoid::kForward);
}

void PneumaticSubsystem::ResetBinHolder()
{
	m_BinHolder.Set(DoubleSolenoid::kReverse);
}

void PneumaticSubsystem::SetToteLifter()
{
	m_ToteLifter.Set(DoubleSolenoid::kReverse);
}

void PneumaticSubsystem::ResetToteLifter()
{
	m_ToteLifter.Set(DoubleSolenoid::kForward);
}

void PneumaticSubsystem::init()
{
	m_ToteLifter.Set(DoubleSolenoid::kForward);
}


