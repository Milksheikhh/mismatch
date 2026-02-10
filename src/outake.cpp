#include "vex.h"

using namespace vex;

extern motor Outake;
extern optical OpticalSensor;
extern controller controller_1;
extern std::string Team;
extern bool Auton;

void outake() {
    while (true) {
        double hue = OpticalSensor.hue();
        
        // Color sorting for red blocks
        if (Team == "blue" && (hue < 35 || hue > 350)) {
            wait(0.05, seconds);
            Outake.spin(reverse, 12.0, voltageUnits::volt);
        }
        // Color sorting for blue blocks  
        else if (Team == "red" && (hue > 200 && hue < 260)) {
            wait(0.05, seconds);
            Outake.spin(reverse, 12.0, voltageUnits::volt);
        }
        if (Auton){
            Outake.spin(forward, 12.0, voltageUnits::volt);
        } 
        else if (controller_1.ButtonL2.pressing()) {
            Outake.spin(forward, 12.0, voltageUnits::volt);
        } else {
            Outake.stop();
        }
        wait(5, msec);
    }
}