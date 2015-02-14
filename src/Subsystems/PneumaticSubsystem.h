#pragma once

#include "WPILib.h"
#include "SubsystemWithCommand.hpp"

class PneumaticSubsystem : public SubsystemWithCommand<void>
{
	public:
		PneumaticSubsystem();
		void SetToteLifter(bool lift);
		void SetBinHolder(bool hold);

	private:
		DoubleSolenoid 	    m_ToteSolenoid1,
							m_ToteSolenoid2,
							m_BinSolenoid1,
					   	    m_BinSolenoid2;
};

