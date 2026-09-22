#include "AccessControlSystem.h"
#include <iostream>

AccessControlSystem::AccessControlSystem(const std::string& n)
 : ResponseComponent(n) { }

bool AccessControlSystem::lockArea(const std::string& area) {
    bool inserted = lockedAreas.insert(area).second;
    if (inserted) {
        std::cout << getName() << ": " << area << " is now locked down." << std::endl;
        if (mediator) {
            mediator->areaSecured(this);
        }
    }
    return inserted;
}

bool AccessControlSystem::unlockArea(const std::string& area) {
    bool removed = lockedAreas.erase(area) > 0;
    if (removed) {
        std::cout << getName() << ": " << area << " has been unlocked." << std::endl;
    }
    return removed;
}


bool AccessControlSystem::isLocked(const std::string& area) const {
    return lockedAreas.count(area) > 0;
}