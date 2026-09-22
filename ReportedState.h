#ifndef REPORTED_STATE_H
#define REPORTED_STATE_H
#include "IncidentState.h"

class ReportedState : public IncidentState {
public:
    void handle(Incident* incident);
    bool canCancel() const;
    std::string name() const;
};
#endif
