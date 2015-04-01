#include "../Main.h"


class Auto : public Command
{
	Auto()
	{
	    Requires (&Main::getIntake());
		Requires (&Main::getPneumatics());
		Requires (&Main::getDrive());
	}
	
	void Initialize() {}
	
	void Execute()
	{
		double t = TimeSinceInitialized();
		
        if (t > 1 && t < 2)
        {
            Main::getPneumatics().SetToteLifter();
            Main::getIntake().SetReverseIntakeSpeed(0.3);
        }
        
        else if(t > 3 && t < 4.5)
        {
            Main::getIntake().SetIntakeSpeed(0.2);
            Main::getDrive().DriveMecanum(0.0, 0.2, 0.0);
        }
        
        else if(t > 5 && t < 6)
        {
            Main::getIntake().SetIntakeSpeed(0.0);
            Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
            Main::getPneumatics().ResetToteLifter();
        }
        
        else if(t > 7 && t < 8)
        {
            Main::getDrive().DriveMecanum(0.0, 0.2, 0.0);
        }
        
        else if(t > 9 && t < 10)
        {
            Main::getDrive().DriveMecanum(0.0, 0.0, 0.35);
        }
        
        else if(t > 11 && t < 14)
        {
            Main::getDrive().DriveMecanum(0.0, 0.5, 0.0);
        }
        
        else if(t > 14)
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

