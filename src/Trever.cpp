#include "Trever.h"

Trever::Trever()
{
	speedMove = 0;
	speedRotate = 0;
}

enum AutoState
{
	eSTART,
	eDRIVE_FORWARD,
	eROTATE,
	eSTOP
};

void Trever::Autonomous()
{
	AutoState state = eSTART;
	Timer* autoTimer = new Timer();

	autoTimer->Start();
	double startTime;


	while (IsAutonomous() && IsEnabled())
	{
		switch (state)
		{
			case eSTART:
				startTime = autoTimer->GetPPCTimestamp();
				state = eDRIVE_FORWARD;
				break;
			case eDRIVE_FORWARD:
				if(autoTimer->GetPPCTimestamp() < (startTime + AUTO_DRIVE_TIME))
				{
					speedMove = 0.8;
					speedRotate = 0;
					MechanismSet();
				}
				else
				{
					startTime = autoTimer->GetPPCTimestamp();
					state = eROTATE;
				}
				break;
			case eROTATE:
				if(autoTimer->GetPPCTimestamp() < (startTime + AUTO_ROTATE_TIME))
				{
					speedMove = 0;
					speedRotate = 1.0;
					MechanismSet();
				}
				else
				{
					state = eSTOP;
				}
				break;
			case eSTOP:
				speedMove = 0;
				speedRotate = 0;
				MechanismSet();
				break;
		}
		Wait(0.005);
	}
}

void Trever::OperatorControl()
{
	Components& components = Components::getInstance();

	while (IsOperatorControl() && IsEnabled())
	{
		speedMove = components.gamepad.GetLeftY();
		speedRotate = components.gamepad.GetRightX();
		MechanismSet();

		Wait(0.005);
	}
}


void Trever::MechanismSet()
{
	Components& components = Components::getInstance();
	components.drivetrain.SetSpeed(speedMove, -speedRotate);
}


START_ROBOT_CLASS(Trever);

