#ifndef DISPATCHED_STATE_H
#define DISPATCHED_STATE_H
#include "IncidentState.h"

class DispatchedState : public IncidentState {
public:
    void handle(Incident* incident);
    bool canCancel() const { return true; }
    std::string name() const { return "Dispatched"; }
};
#endif
