
#pragma once
#include "Commands/Command.h"


class Auto: public Command
{
	public:
		Auto();
		virtual void Initialize();
		virtual void Execute();
		virtual bool IsFinished();
		virtual void End();
		virtual void Interrupted();
};


