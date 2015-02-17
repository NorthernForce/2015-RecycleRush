#include "PneumaticSubsystem.h"
#include "WPIlib.h"

PneumaticSubsystem::PneumaticSubsystem () {

	virtual void WhenPressed(Command*Command);
	virtual void WhenHeld(Command*command);
	virtual void WhenReleased(Command*command);
}
