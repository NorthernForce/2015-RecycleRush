#include "../Main.h"


class Auto : public Command
{
	Auto()
	{
		Requires (&Main::getPneumatics());
		Requires (&Main::getDrive());
	}
	
	void Initialize() {}
	
	void Execute()
	{
		double t = TimeSinceInitialized();
		
		if(t > 1 && t < 3.3)
		{
			Main::getDrive().DriveMecanum(0.0, 0.5, 0.0);
		}
		
		else if(t > 3.3)
		{
			Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
		}
	}

	bool IsFinished()
	{
		return TimeSinceInitialized() > 15;
	}
	
	void End()
	{
		Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
	}
	
	void Interrupted() {}

};
