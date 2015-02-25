#pragma once

#include "WPILib.h"
#include "SubsystemWithCommand.hpp"

class PneumaticSubsystem : public SubsystemWithCommand<void>
{
	public:
		PneumaticSubsystem();

		void SetBinOrienter();
		void ResetBinOrienter();

		void SetBinHolder();
		void ResetBinHolder();

		void SetToteLifter();
		void ResetToteLifter();

		void init();

	private:
		DoubleSolenoid 	    m_BinOrienter;
		DoubleSolenoid		m_BinHolder;
		DoubleSolenoid		m_ToteLifter;
};

