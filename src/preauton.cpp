#include "vex.h"

using namespace vex;

extern controller controller_1;
extern int AutonRout;
extern std::string Team;

const char* getAutonName(int num) {
    switch(num) {
        case 1: return "Left LG Only";
        case 2: return "Right LG Only";
        case 3: return "Left LG+ML";
        case 4: return "Right LG+ML";
        case 5: return "Left TMG+LG+ML";
        case 6: return "Right BMG+LG+ML";
        default: return "Unknown";
    }
}

void autonSelection() {
    controller_1.Screen.clearScreen();
    controller_1.Screen.setCursor(1, 1);
    controller_1.Screen.print("%d: %s", AutonRout, getAutonName(AutonRout));
    controller_1.Screen.setCursor(2, 1);
    controller_1.Screen.print("Team: %s", Team.c_str());
    
    while (true) {
        bool change = false;

        if (controller_1.ButtonLeft.pressing()) {
            AutonRout--;
            if (AutonRout < 1) AutonRout = 6;
            change = true;
            while (controller_1.ButtonLeft.pressing()) {
                wait(10, msec);
            }
        }
        
        if (controller_1.ButtonRight.pressing()) {
            AutonRout++;
            if (AutonRout > 6) AutonRout = 1;
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