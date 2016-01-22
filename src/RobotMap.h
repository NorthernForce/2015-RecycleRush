#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */


enum XBoxJoystickButtonPort
{
	// Mappings are 1 based, unlike 2015 and beyond
	kXBoxButtonA = 1,
	kXBoxButtonB = 2,
	kXBoxButtonX = 3,
	kXBoxButtonY = 4,
	kXBoxButtonLeft = 5,
	kXBoxButtonRight = 6,
	kXBoxButtonBack = 7,
	kXBoxButtonStart = 8,
	kXBoxButtonLeftJoystick = 9,
	kXBoxButtonRightJoystick = 10,
};



enum Attack3JoystickPort
{
 	kAttackJoystickButtonTrigger = 1,
 	kAttackJoystickButton2 = 2,
 	kAttackJoystickButton3 = 3,
 	kAttackJoystickButton4 = 4,
 	kAttackJoystickButton5 = 5,
 	kAttackJoystickButton6 = 6,
 	kAttackJoystickButton7 = 7,
 	kAttackJoystickButton8 = 8,
 	kAttackJoystickButton9 = 9,
 	kAttackJoystickButton10 = 10,
 	kAttackJoystickButton11 = 11,
	kAttackJoystickButton12 = 12,
};

enum TalonCANAdress
{
	/*kFrontLeftTalon = 0, //PRACTICE ROBOT
	kFrontRightTalon = 1,
	kBackLeftTalon = 2,
	kBackRightTalon = 3,*/


	kFrontLeftTalon = 3, //COMPETITION ROBOT: Wired 180 degrees differently, FL = BR, etc.
	kFrontRightTalon = 2,
	kBackLeftTalon = 1,
	kBackRightTalon = 0,

	kIntakeRight = 8,
	kIntakeLeft = 7,

};


enum JoystickPort
{
    kDriverStickPort = 1,
    kManipulatorStickPort = 2,
	//kXBoxManipulatorPort = 1,
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
