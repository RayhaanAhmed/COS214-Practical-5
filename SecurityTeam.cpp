#include "SecurityTeam.h"
#include <iostream>

SecurityTeam::SecurityTeam(const std::string& n)
 : ResponseComponent(n) { }

void SecurityTeam::respondTo(Incident* incident) {
    std::cout << getName() << ": responding to incident " << incident->getId() << " at " << incident->getLocation() << std::endl;
    if (mediator) {
        mediator->dispatchCompleted(this, incident);
    }
}