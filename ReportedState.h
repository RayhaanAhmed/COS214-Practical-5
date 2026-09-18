#ifndef REPORTED_STATE_H
#define REPORTED_STATE_H
#include "IncidentState.h"

class ReportedState : public IncidentState {
public:
    void handle(Incident* incident);
    bool canCancel() const { return true; }
    std::string name() const { return "Reported"; }
};
#endif
