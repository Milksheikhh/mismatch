#include "vex.h"

using namespace vex;

extern motor L1, L2, L3, R1, R2, R3;
extern controller controller_1;

void movement() {
    double leftSpeed = 0;
    double rightSpeed = 0;
    
    while (true) {
        rightSpeed = (controller_1.Axis3.position() - controller_1.Axis1.position()) / 8.3;
        leftSpeed = (-controller_1.Axis1.position() - controller_1.Axis3.position()) / 8.3;
        
        L1.spin(forward, leftSpeed, voltageUnits::volt);
        L2.spin(forward, leftSpeed, voltageUnits::volt);
        L3.spin(forward, leftSpeed, voltageUnits::volt);
        R1.spin(forward, rightSpeed, voltageUnits::volt);
        R2.spin(forward, rightSpeed, voltageUnits::volt);
        R3.spin(forward, rightSpeed, voltageUnits::volt);
        
        wait(5, msec);
    }
}

void move(double degree) {
    R1.spinFor(forward, degree, degrees, false);
    R2.spinFor(forward, degree, degrees, false);
    R3.spinFor(forward, degree, degrees, false);
    L1.spinFor(reverse, degree, degrees, false);
    L2.spinFor(reverse, degree, degrees, false);
    L3.spinFor(forward, degree, degrees);
}

void rotate(double degree) {
    R1.spinFor(forward, degree, degrees, false);
    R2.spinFor(forward, degree, degrees, false);
    R3.spinFor(forward, degree, degrees, false);
    L1.spinFor(forward, degree, degrees, false);
    L2.spinFor(forward, degree, degrees, false);
    L3.spinFor(forward, degree, degrees);
}