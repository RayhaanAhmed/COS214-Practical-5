#include "FacilitiesTeam.h"
#include <iostream>

FacilitiesTeam::FacilitiesTeam(const std::string& n)
 : ResponseComponent(n) { }

void FacilitiesTeam::assistWithArea(const std::string& area) {
    std::cout << getName() << ": moving in to secure " << area << std::endl;
    if (mediator) {
        mediator->requestAreaLockdown(this, area);
    }
}