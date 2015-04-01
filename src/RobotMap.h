#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */


//Probably unnecessary
static const int kBallDataPort = 1726;

enum XBoxJoystickButtonPort
{
	// New mappings starting in 2015
	kXBoxButtonA = 0,
	kXBoxButtonB = 1,
	kXBoxButtonX = 2,
	kXBoxButtonY = 3,
	kXBoxButtonLeft = 4,
	kXBoxButtonRight = 5,
	kXBoxButtonBack = 6,
	kXBoxButtonStart = 7,
	kXBoxButtonLeftJoystick = 8,
	kXBoxButtonRightJoystick = 9,
};



enum Attack3JoystickPort
{
 	kAttackJoystickButtonTrigger = 0,
 	kAttackJoystickButton2 = 1,
 	kAttackJoystickButton3 = 2,
 	kAttackJoystickButton4 = 3,
 	kAttackJoystickButton5 = 4,
 	kAttackJoystickButton6 = 5,
 	kAttackJoystickButton7 = 6,
 	kAttackJoystickButton8 = 7,
 	kAttackJoystickButton9 = 8,
 	kAttackJoystickButton10 = 9,
 	kAttackJoystickButton11 = 10,
	kAttackJoystickButton12 = 11,
};

enum TalonCANAdress
{
	/*
	 *	kFrontLeftTalon = 0, // PRACTICE ROBOT
	 *	kFrontRightTalon = 1,
	 *	kBackLeftTalon = 2,
	 *	kBackRightTalon = 3,
	 */
	
	kFrontLeftTalon = 3, // COMPETITION ROBOT: Wired 180 degrees differently, FL = BR, etc.
	kFrontRightTalon = 2,
	kBackLeftTalon = 1,
	kBackRightTalon = 0,
	
	kIntakeRight = 8,
	kIntakeLeft = 7,

};


enum JoystickPort
{
    kDriverStickPort = 0,
    kManipulatorStickPort = 1,
};

enum RelayPort
{
	kCompressorModule = 1,
	kCompressorRelay = 1,
	kIntakeModule = 1,
	kIntakeRelay = 2,
};

enum DigitalIOPort
{
	kCompressorSwitchModule = 1,
	kCompressorSwitch = 1,

	//Probably unnecessary
	k_targetingUltrasonicSerialMode = 3,
	k_targetingUltrasonicOn = 2,
};

enum AnalogIOPort
{
	//Probably unnecessary
	//k_MaxbotixUltrasonic = 1,
	k_targetingUltrasonic = 2,
	k_pressureChannel = 3,
};

enum SolenoidPort
{
	kSolenoidPort1 = 1,
	kSolenoidPort2 = 2,
	kSolenoidPort3 = 3,
	kSolenoidPort4 = 4,
	kSolenoidPort5 = 5,
	kSolenoidPort6 = 6,
	kSolenoidPort7 = 7,
	kSolenoidPort0 = 0,

};

static const float kDeadbandLimit = 0.01;
static const float kMaxDriveVoltage = 12.0;
static const float kMaxDriveRPM = 475.0;
static const float kRevsPerFoot = 12.0/(2.0*3.14159*3.0); /* 12in / (1ft * 2.0pi r(in)) */
static const int kEncoderPulsesPerRev = 256;
