#include "PneumaticSubsystem.h"
#include "../RobotMap.h"


PneumaticSubsystem::PneumaticSubsystem():
		SubsystemWithCommand<void>("PneumaticSubsystem"),
		m_ToteSolenoid1(kSolenoidForward1, kSolenoidReverse1),
		m_ToteSolenoid2(kSolenoidForward1, kSolenoidReverse1),
		m_BinSolenoid1(kSolenoidForward3, kSolenoidReverse3),
		m_BinSolenoid2(kSolenoidForward3, kSolenoidReverse3) {}

void PneumaticSubsystem::SetToteLifter(bool lift)
	{
		if(lift)
		{
			m_ToteSolenoid1.Set(DoubleSolenoid::kForward);
			m_ToteSolenoid2.Set(DoubleSolenoid::kForward);
		}

		else
		{
			m_ToteSolenoid1.Set(DoubleSolenoid::kOff);
			m_ToteSolenoid2.Set(DoubleSolenoid::kOff);

		}
	}

void PneumaticSubsystem::SetBinHolder(bool hold)
	{
		if(hold)
		{
			m_BinSolenoid1.Set(DoubleSolenoid::kForward);
			m_BinSolenoid2.Set(DoubleSolenoid::kForward);
		}

		else
		{
			m_BinSolenoid1.Set(DoubleSolenoid::kOff);
			m_BinSolenoid2.Set(DoubleSolenoid::kOff);
		}
	}
