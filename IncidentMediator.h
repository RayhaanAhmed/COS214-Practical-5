#ifndef INCIDENT_MEDIATOR_H
#define INCIDENT_MEDIATOR_H
#include <string>
class ResponseComponent;
class AccessControlSystem;
class Incident;

class IncidentMediator {
public:
    virtual void dispatchCompleted(ResponseComponent* colleague, Incident* incident) = 0;
    virtual void requestBackup(ResponseComponent* requester, Incident* incident) = 0;
    virtual void requestAreaLockdown(ResponseComponent* requester, const std::string& area) = 0;
    virtual void areaSecured(AccessControlSystem* colleague) = 0;
    virtual ~IncidentMediator() {}
};
#endif
