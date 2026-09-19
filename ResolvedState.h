#ifndef RESOLVED_STATE_H
#define RESOLVED_STATE_H
#include "IncidentState.h"

class ResolvedState : public IncidentState {
public:
    void handle(Incident* incident); // no-op: terminal state
    bool canCancel() const;// rule: cannot cancel a resolved incident
    std::string name() const;
};
#endif
