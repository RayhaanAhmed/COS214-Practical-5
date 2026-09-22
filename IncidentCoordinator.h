#ifndef INCIDENT_COORDINATOR_H
#define INCIDENT_COORDINATOR_H
#include "IncidentMediator.h"
#include "SecurityTeam.h"
#include "MedicalTeam.h"
#include "FacilitiesTeam.h"
#include "AccessControlSystem.h"

class IncidentCoordinator : public IncidentMediator {
private:
    SecurityTeam* security;
    MedicalTeam* medical;
    FacilitiesTeam* facilities;
    AccessControlSystem* access;
public:
    IncidentCoordinator(SecurityTeam* s, MedicalTeam* m, FacilitiesTeam* f, AccessControlSystem* a);
    void dispatchCompleted(ResponseComponent* colleague, Incident* incident);
    void requestBackup(ResponseComponent* requester, Incident* incident);
    void requestAreaLockdown(ResponseComponent* requester, const std::string& area);
    void areaSecured(AccessControlSystem* colleague);
};
#endif
