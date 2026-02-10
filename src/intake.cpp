#include "vex.h"

using namespace vex;

extern motor Intake;
extern controller controller_1;

void intake() {
    while (true) {
        if (controller_1.ButtonR1.pressing()) {
            Intake.spin(forward, 12.0, voltageUnits::volt);
        } else if (controller_1.ButtonR2.pressing()) {
            Intake.spin(reverse, 12.0, voltageUnits::volt);
        } else {
            Intake.stop();
        }
        wait(5, msec);
    }
}