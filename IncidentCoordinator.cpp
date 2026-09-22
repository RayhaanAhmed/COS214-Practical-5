#include "IncidentCoordinator.h"
#include <iostream>

IncidentCoordinator::IncidentCoordinator(SecurityTeam* s, MedicalTeam* m, FacilitiesTeam* f, AccessControlSystem* a)
 : security(s), medical(m), facilities(f), access(a) 
{ 
    security->setMediator(this);
    medical->setMediator(this);
    facilities->setMediator(this);
    access->setMediator(this);
}

void IncidentCoordinator::dispatchCompleted(ResponseComponent* colleague, Incident* incident) {
    if (colleague == security) {  //since securities are the ones who get there first, coz they always on duty at the campus
        medical->standBy(incident);
        facilities->assistWithArea(incident->getLocation());
    }
}

void IncidentCoordinator::requestBackup(ResponseComponent* requester, Incident* incident) { //if situation is worse/bigger than expected
    if (requester == security) {
        std::cout << security->getName() << " requested backup for incident " << incident->getId() << " - dispatching facilities to assist.\n";
        facilities->assistWithArea(incident->getLocation());
    } else if (requester == facilities) {
        std::cout << facilities->getName() << " requested backup for incident " << incident->getId() << " - alerting security.\n";
        security->respondTo(incident);
    }
}

void IncidentCoordinator::requestAreaLockdown(ResponseComponent* requester, const std::string& area) {
    access->lockArea(area);
}

void IncidentCoordinator::areaSecured(AccessControlSystem* colleague) {
    if (colleague == access) {
        std::cout << security->getName() << " confirms area secure, standing down." << std::endl;
        std::cout << facilities->getName() << " confirms lockdown complete, leaving scene." << std::endl;
    }
}