#include "vex.h"

using namespace vex;

// Brain
brain Brain;

// Controller
controller controller_1(primary);

// Drive motors
motor L1(PORT7, ratio18_1, false);
motor L2(PORT20, ratio18_1, false);
motor L3(PORT18, ratio18_1, false);
motor R1(PORT4, ratio18_1, false);
motor R2(PORT11, ratio18_1, false);
motor R3(PORT14, ratio18_1, false);

// Pneumatics
digital_out WingPiston(Brain.ThreeWirePort.H);
digital_out ScraperPiston(Brain.ThreeWirePort.G);

// Intake/Outake
motor Intake(PORT13, ratio18_1, false);
motor Outake(PORT10, ratio18_1, true);

// Sensors
optical OpticalSensor(PORT9);
optical AutonOpticalSensor(PORT19);

// Global variables
std::string Team = "blue";
bool Wing = false;
bool Scraper = false;
bool Auton = false;
bool AutonOutake = false;
int AutonRout = 1;