#pragma once

/**
 * The RobotMap is a mapping from the ports sensors and actuators are wired into
 * to a variable name. This provides flexibility changing wiring, makes checking
 * the wiring easier and significantly reduces the number of magic numbers
 * floating around.
 */

// For example to map the left and right motors, you could define the
// following variables to use with your drivetrain subsystem.
// #define LEFTMOTOR 1
// #define RIGHTMOTOR 2

// If you are using multiple modules, make sure to define both the port
// number and the module. For example you with a rangefinder:
// #define RANGE_FINDER_PORT 1
// #define RANGE_FINDER_MODULE 1

 /*
  * @brief The button ports on the XBox Joystick, as interpreted by the cRIO.
  */

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

/*
 * @brief The button ports on the Attack 3 Joystick.
 */
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

enum TalonCANAdress {

	kFrontLeftTalon = 2, //1, //0, //4
	kFrontRightTalon = 1, //3, //1, //5,
	kBackLeftTalon = 4, //2, //2, //6,
	kBackRightTalon = 3, //4, //3, //3,

	kIntakeRight = 8,
	kIntakeLeft = 7,

	//kFrontLeftMotor = 0,
	//kFrontRightMotor = 1,
	//kRearLeftMotor = 2,
	//kRearRightMotor = 3

// For Tango on 2nd 2014 robot
//	kBackRightTalon = 14,
//	kFrontRightTalon = 12,
//	kBackLeftTalon = 13,
//	kFrontLeftTalon = 11,

//	kBackRightTalon = 8,
//	kFrontRightTalon = 6,
//	kBackLeftTalon = 7,
//	kFrontLeftTalon = 5,
};


enum JoystickPort {
    kDriverStickPort = 0,
    kManipulatorStickPort = 1,
};

enum RelayPort {
	kCompressorModule = 1,
	kCompressorRelay = 1,
	kIntakeModule = 1,
	kIntakeRelay = 2,
};

enum DigitalIOPort {
	kCompressorSwitchModule = 1,
	kCompressorSwitch = 1,
	k_targetingUltrasonicSerialMode = 3,
	k_targetingUltrasonicOn = 2,
};

enum AnalogIOPort
{
	//k_MaxbotixUltrasonic = 1,
	k_targetingUltrasonic = 2,
	k_pressureChannel = 3,
};

enum SolenoidPort {
	kSolenoidPort1 = 1,
	kSolenoidPort2 = 2,
	kSolenoidPort3 = 3,
	kSolenoidPort4 = 4,
	kSolenoidPort5 = 5,
	kSolenoidPort6 = 6,

};

static const float kDeadbandLimit = 0.01;
static const float kMaxDriveVoltage = 12.0;
static const float kMaxDriveRPM = 475.0;
static const float kRevsPerFoot = 12.0/(2.0*3.14159*3.0); /* 12in / (1ft * 2.0pi r(in)) */
static const int kEncoderPulsesPerRev = 256;
