#include "vex.h"

using namespace vex;

extern motor Intake;
extern motor Outake;
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
            AutonOutake = true;
            while (true) {
                if (Outake.isSpinning() == false) {
                    break;
                }
            }
            move(12);
            move(-12);
            break;

        case 2:
            move(12);
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
    }
    
    Auton = false;
}