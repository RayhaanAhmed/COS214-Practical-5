#ifndef IN_PROGRESS_STATE_H
#define IN_PROGRESS_STATE_H
#include "IncidentState.h"

class InProgressState : public IncidentState {
public:
    void handle(Incident* incident);
    bool canCancel() const { return true; }
    std::string name() const { return "InProgress"; }
};
#endif
