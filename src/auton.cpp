#include "vex.h"

using namespace vex;

extern motor Intake;
extern motor Outake;
extern optical AutonOpticalSensor;
extern std::string Team;
extern bool Auton;
extern bool autonOutake;

extern void move(double degree);
extern void rotate(double degree);
extern void outake();


void autonRoutine() {
    Auton = true;
    Intake.spin(forward);
    move(24);
    Intake.stop();
    rotate(90);
    move(24);
    Intake.spin(reverse);
    wait(1, seconds);
    Intake.stop();
    rotate(180);
    move(24);
    rotate(-90);
    move(24);
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
    }
    move(-12);
    Intake.spin(forward);
    autonOutake = true;
    while (true) {
        if (Outake.isSpinning() == false) {
            break;
        }
    }
    move(12);
    move(-12);
    Auton = false;
}