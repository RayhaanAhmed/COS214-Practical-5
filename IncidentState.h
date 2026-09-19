#ifndef INCIDENT_STATE_H
#define INCIDENT_STATE_H

#include <string>

class Incident;

class IncidentState {
public:
    virtual void handle(Incident* incident) = 0;
    virtual bool canCancel() const = 0;
    virtual std::string name() const = 0;
    virtual ~IncidentState() {}
};
#endif
