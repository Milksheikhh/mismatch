#include "vex.h"

using namespace vex;

extern digital_out WingPiston, ScraperPiston;
extern controller controller_1;
extern bool Wing, Scraper;

void wing() {
    while (true) {
        if (controller_1.ButtonY.pressing()) {
            Wing = !Wing;
            WingPiston.set(Wing);
            while (controller_1.ButtonY.pressing()) {
                wait(10, msec);
            }
        }
        wait(5, msec);
    }
}

void scraper() {
    while (true) {
        if (controller_1.ButtonB.pressing()) {
            Scraper = !Scraper;
            ScraperPiston.set(Scraper);
            // Debounce
            while (controller_1.ButtonB.pressing()) {
                wait(10, msec);
            }
        }
        wait(5, msec);
    }
}