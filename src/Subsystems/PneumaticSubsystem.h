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

		void SetWheelActuator();
		void ResetWheelActuator();

		void SetWedgeBar();
		void ResetWedgeBar();

		void init();

	private:
		DoubleSolenoid		m_BinHolder;
		DoubleSolenoid		m_ToteLifter;
		DoubleSolenoid 	    m_WheelActuator;
		DoubleSolenoid 		m_WedgeBar;
		Compressor			m_compressor;
};

