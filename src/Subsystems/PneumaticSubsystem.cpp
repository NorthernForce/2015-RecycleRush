#include "PneumaticSubsystem.h"
#include "../RobotMap.h"


PneumaticSubsystem::PneumaticSubsystem():
		SubsystemWithCommand<void>("PneumaticSubsystem"),
		m_BinOrienter(kSolenoidPort3, kSolenoidPort4),
		m_BinHolder(kSolenoidPort7, kSolenoidPort0),
		m_ToteLifter(kSolenoidPort6, kSolenoidPort5),
		m_WheelActuator(kSolenoidPort1, kSolenoidPort2),
		m_compressor(kCompressorModule)
		{
			m_compressor.Start();
		}


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

void PneumaticSubsystem::SetWheelActuator()
{
	m_WheelActuator.Set(DoubleSolenoid::kForward);
}

void PneumaticSubsystem::ResetWheelActuator()
{
	m_WheelActuator.Set(DoubleSolenoid::kReverse);
}

void PneumaticSubsystem::init()
{

	m_ToteLifter.Set(DoubleSolenoid::kReverse); //Added to set default state as down
	m_BinOrienter.Set(DoubleSolenoid::kReverse);
	m_BinHolder.Set(DoubleSolenoid::kOff);
	m_WheelActuator.Set(DoubleSolenoid::kReverse);
}


