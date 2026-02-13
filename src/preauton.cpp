#include "vex.h"

using namespace vex;

extern controller controller_1;
extern int AutonRout;
extern std::string Team;

const char* getAutonName(int num) {
    switch(num) {
        case 1: return "Right Long Goal";
        case 2: return "Left Long Goal";
        case 3: return "Right Short Goal";
        case 4: return "Left Short Goal";
        case 5: return "Skills";
        default: return "Unknown";
    }
}

void autonSelection() {
    controller_1.Screen.clearScreen();
    controller_1.Screen.setCursor(1, 1);
    controller_1.Screen.print("%d: %s", AutonRout, getAutonName(AutonRout));
    controller_1.Screen.setCursor(2, 1);
    controller_1.Screen.print("Team: %s", Team.c_str());
    controller_1.Screen.setCursor(3, 1);
    controller_1.Screen.print("L/R=auton U/D=team B=lock");
    
    while (true) {
        bool change = false;

        if (controller_1.ButtonLeft.pressing()) {
            AutonRout--;
            if (AutonRout < 1) AutonRout = 5;
            change = true;
            while (controller_1.ButtonLeft.pressing()) {
                wait(10, msec);
            }
        }
        
        if (controller_1.ButtonRight.pressing()) {
            AutonRout++;
            if (AutonRout > 5) AutonRout = 1;
            change = true;
            while (controller_1.ButtonRight.pressing()) {
                wait(10, msec);
            }
        }

        if (controller_1.ButtonUp.pressing() || controller_1.ButtonDown.pressing()) {
            if (Team == "blue") {
                Team = "red";
            } else {
                Team = "blue";
            }
            change = true;
            while (controller_1.ButtonUp.pressing() || controller_1.ButtonDown.pressing()) {
                wait(10, msec);
            }
        }

        if (change) {
            controller_1.Screen.clearScreen();
            controller_1.Screen.setCursor(1, 1);
            controller_1.Screen.print("%d: %s", AutonRout, getAutonName(AutonRout));
            controller_1.Screen.setCursor(2, 1);
            controller_1.Screen.print("Team: %s", Team.c_str());
            controller_1.Screen.setCursor(3, 1);
            controller_1.Screen.print("L/R=auton U/D=team B=lock");
        }
        
        if (controller_1.ButtonB.pressing()) {
            controller_1.Screen.clearScreen();
            controller_1.Screen.setCursor(1, 1);
            controller_1.Screen.print("LOCKED!");
            controller_1.Screen.setCursor(2, 1);
            controller_1.Screen.print("%s", getAutonName(AutonRout));
            controller_1.Screen.setCursor(3, 1);
            controller_1.Screen.print("Team: %s", Team.c_str());
            
            while (controller_1.ButtonB.pressing()) {
                wait(10, msec);
            }
            wait(1000, msec);
            break;
        }
        
        wait(20, msec);
    }
}