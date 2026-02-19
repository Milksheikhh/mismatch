#include "vex.h"

using namespace vex;

extern motor Intake;
extern motor Outake;
extern motor L1;
extern motor L2;
extern motor L3;
extern motor R1;
extern motor R2;
extern motor R3;
extern optical AutonOpticalSensor;
extern std::string Team;
extern bool Auton;
extern bool AutonOutake;
extern int AutonRout;

extern void move(double degree);
extern void rotate(double degree);
extern void outake();

void autonRoutine() {
    Auton = true;
    switch (AutonRout) {
        case 1:
            L1.setVelocity(25, percent);
            L2.setVelocity(25, percent);
            L3.setVelocity(25, percent);
            R1.setVelocity(25, percent);
            R2.setVelocity(25, percent);
            R3.setVelocity(25, percent);
            move(450);
            Intake.spin(forward);
            wait(1, seconds);
            move(100);
            wait(1, seconds);
            break;

        case 2:
            break;
            
        case 3:
            move(12);
            break;
            
        case 4:
            move(12);
            break;
            
        case 5:
            move(12);
            break;
        case 6:
            move(12);
            break;
    }
    
    Auton = false;
}
