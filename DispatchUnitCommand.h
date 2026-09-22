#ifndef DISPATCH_UNIT_COMMAND_H
#define DISPATCH_UNIT_COMMAND_H
#include "Command.h"

#include "Incident.h"
#include "DispatchOrder.h"

class DispatchUnitCommand : public Command {
private:
    DispatchOrder* order; // command owns the (possibly decorated) receiver chain
    Incident* incident;                   // non-owning
public:
    DispatchUnitCommand(DispatchOrder* o, Incident* inc);
    void execute();
    void undo();
    ~DispatchUnitCommand();
};
#endif
