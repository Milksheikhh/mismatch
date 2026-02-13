#include "vex.h"

using namespace vex;

extern void movement();
extern void intake();
extern void outake();
extern void wing();
extern void scraper();
extern void autonRoutine();
extern void initializeRandomSeed();
extern void autonSelection();

extern motor L1, L2, L3, R1, R2, R3, Intake, Outake;
extern controller controller_1;
extern digital_out WingPiston, ScraperPiston;
extern optical OpticalSensor, AutonOpticalSensor;
extern std::string Team;
extern bool Wing, Scraper, Auton;

thread movementThread;
thread intakeThread;
thread outakeThread;
thread wingThread;
thread scraperThread;
thread centerThread;
thread autonSelectionThread;

void driver() {
    intakeThread = thread(intake);
    outakeThread = thread(outake);
    wingThread = thread(wing);
    scraperThread = thread(scraper);
    movement();
}

int main() {
    L1.setVelocity(100, percent);
    L2.setVelocity(100, percent);
    L3.setVelocity(100, percent);
    R1.setVelocity(100, percent);
    R2.setVelocity(100, percent);
    R3.setVelocity(100, percent);
    Intake.setVelocity(100, percent);
    Outake.setVelocity(100, percent);
    autonSelectionThread = thread(autonSelection);
    
    competition Competition = competition();
    Competition.drivercontrol(driver);
    Competition.autonomous(autonRoutine);
    
    while (true) {
        wait(100, msec);
    }
}