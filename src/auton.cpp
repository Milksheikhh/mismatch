#include "vex.h"

using namespace vex;

extern motor Intake;
extern optical AutonOpticalSensor;
extern std::string Team;
extern bool Auton;

extern void move(double degree);
extern void rotate(double degree);
extern void outake();


void autonRoutine() {
    while (true) {
        Intake.spin(forward);
        double hue = AutonOpticalSensor.hue();
        
        if (Team == "blue" && (hue < 35 || hue > 350)) {
            Intake.stop();
            break;
        } else if (Team == "red" && (hue > 200 && hue < 260)) {
            Intake.stop();
            break;
        }
        wait(5, msec);
        Auton = false;
    }
}