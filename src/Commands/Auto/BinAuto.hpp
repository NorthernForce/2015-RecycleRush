#pragma once

#include "Main.h"

class BinAuto : public Command
{
	public:

		BinAuto()
		{
			Requires (&Main::getPneumatics());
			Requires (&Main::getIntake());
			Requires (&Main::getDrive());
		}

		void Initialize()
		{
			//Main::getPneumatics().SetToteLifter();
		}

		void Execute()
		{
			double t = TimeSinceInitialized();


			if (t > .1 && t < 1.1)
			{
				Main::getPneumatics().SetToteLifter();
				Main::getIntake().SetReverseIntakeSpeed(0.4);
			}

			else if(t > 1.2 && t < 2)
			{
				Main::getIntake().SetIntakeSpeed(0.2);
				Main::getDrive().DriveMecanum(0.0, 0.4, 0.0);
			}

			else if(t > 2.1 && t < 3.1)
			{
				Main::getIntake().SetIntakeSpeed(0.0);
				Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
				Main::getPneumatics().ResetToteLifter();
			}

			else if(t > 3.2 && t < 4)
			{
				Main::getDrive().DriveMecanum(0.0, -0.5, 0.0);
			}


		}

		bool IsFinished()
		{
			return TimeSinceInitialized() > 15;
		}

		void End()
		{
			Main::getIntake().SetIntakeSpeed(0.0);
			Main::getDrive().DriveMecanum(0.0, 0.0, 0.0);
		}

		void Interrupted() {}

};
