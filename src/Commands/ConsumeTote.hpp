#pragma once

#include "Commands/Command.h"


class ConsumeTote: public Command
{
	public:
		ConsumeTote() {}
		virtual void Initialize() {}
		virtual void Execute() {}
		virtual bool IsFinished() { return false; }
		virtual void End() {}
		virtual void Interrupted() {}
};

