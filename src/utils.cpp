#include "vex.h"

using namespace vex;

extern brain Brain;

void initializeRandomSeed() {
    wait(100, msec);
    double randomVal = Brain.Battery.voltage(voltageUnits::mV) + 
                       Brain.Battery.current(currentUnits::amp) * 100 + 
                       Brain.Timer.systemHighResolution();
    srand(static_cast<unsigned int>(randomVal));
}

std::string convertColorToString(color col) {
    if (col == red) return "red";
    if (col == green) return "green";
    if (col == blue) return "blue";
    if (col == white) return "white";
    if (col == yellow) return "yellow";
    if (col == orange) return "orange";
    if (col == purple) return "purple";
    if (col == cyan) return "cyan";
    if (col == black) return "black";
    if (col == transparent) return "transparent";
    return "";
}

void playVexcodeSound(const char* sound_name) {
    printf("VEXPlaySound:%s\n", sound_name);
    wait(5, msec);
}