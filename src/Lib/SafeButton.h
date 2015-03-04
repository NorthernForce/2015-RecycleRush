#pragma once
#include <vector>
#include <utility>
#include "Commands/Command.h"
#include "Buttons/JoystickButton.h"
#include "Buttons/HeldButtonScheduler.h"
#include "Buttons/PressedButtonScheduler.h"
#include "Buttons/ReleasedButtonScheduler.h"
#include "Buttons/ToggleButtonScheduler.h"
#include "Buttons/CancelButtonScheduler.h"

/**
 * Joystick button class that keeps track of it's own memory!
 * Not that it's really necessary, but the WhenPressed, WhileHeld,
 * etc. funcitions now take a template argument so when setting up
 * buttons, there are now no un-deleted news.
 *
 * Note that commands used with this kind of button cannot be
 * constructed with any arguments, but this should not be a problem
 * as any init for the command should really happen in the command's
 * init function and not in the constructor.
 */

class SafeButton : public JoystickButton
{
	public:
		SafeButton(GenericHID* joystick, int buttonNumber) :
			JoystickButton(joystick, buttonNumber) {}

		virtual ~SafeButton()
		{
			for(unsigned int i = 0; i < commands.size(); ++i)
			{
				delete commands[i].first;
				delete commands[i].second;
			}
		}

		template<class C>
		void WhenPressed()
		{
			C* command = new C;
			PressedButtonScheduler* pbs = new PressedButtonScheduler(Grab(), this, command);
			pbs->Start();

			commands.push_back(std::make_pair(command, pbs));
		}

		template<class C>
		void WhileHeld()
		{
			C* command = new C;
			HeldButtonScheduler* hbs = new HeldButtonScheduler(Grab(), this, command);
			hbs->Start();

			commands.push_back(std::make_pair(command, hbs));
		}

		template<class C>
		void WhenReleased()
		{
			C* command = new C;
			ReleasedButtonScheduler* rbs = new ReleasedButtonScheduler(Grab(), this, command);
			rbs->Start();

			commands.push_back(std::make_pair(command, rbs));
		}

		template<class C>
		void CancelWhenPressed()
		{
			C* command = new C;
			CancelButtonScheduler* cbs = new CancelButtonScheduler(Grab(), this, command);
			cbs->Start();

			commands.push_back(std::make_pair(command, cbs));
		}

		template<class C>
		void ToggleWhenPressed()
		{
			C* command = new C;
			ToggleButtonScheduler* tbs = new ToggleButtonScheduler(Grab(), this, command);
			tbs->Start();

			commands.push_back(std::make_pair(command, tbs));
		}

	private:
    	std::vector< std::pair<Command*,ButtonScheduler*> > commands;
};
