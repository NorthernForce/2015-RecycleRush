
#pragma once

#include "Commands/Command.h"


class TriggerIntake: public Command
{
	public:
		TriggerIntake();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};




