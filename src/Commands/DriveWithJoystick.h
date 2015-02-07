#pragma once

#include "Commands/Command.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class DriveWithJoystick: public Command {
public:
	DriveWithJoystick();
	virtual void Initialize();
	virtual void Execute();
	virtual bool IsFinished();
	virtual void End();
	virtual void Interrupted();
};
