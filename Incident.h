#ifndef INCIDENT_H
#define INCIDENT_H
#include <memory>
#include <iostream>
#include <string>
#include "IncidentState.h"

// Context (State pattern)
class Incident {
private:
    std::string id;
    std::string type;
    std::string location;
    int severity;
    std::unique_ptr<IncidentState> state; // owned; replaced wholesale on transition
public:
    Incident(const std::string& id_, const std::string& type_, const std::string& location_, int severity_);
    void setState(std::unique_ptr<IncidentState> newState);
    void advance(); // delegates to state->handle(this)
    bool canCancel() const;
    std::string getStatusName() const;
    std::string getLocation() const;
    std::string getType() const;
    std::string getId() const;
    int getSeverity() const;
};
#endif
