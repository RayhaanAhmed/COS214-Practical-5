#ifndef ESCALATED_STATE_H
#define ESCALATED_STATE_H
#include "IncidentState.h"

class EscalatedState : public IncidentState {
public:
    void handle(Incident* incident);
    bool canCancel() const { return true; }
    std::string name() const { return "Escalated"; }
};
#endif
