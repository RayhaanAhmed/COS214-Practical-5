#ifndef DISPATCH_UNIT_COMMAND_H
#define DISPATCH_UNIT_COMMAND_H
#include "Command.h"
#include <memory>
class DispatchOrder;
class Incident;

class DispatchUnitCommand : public Command {
private:
    std::unique_ptr<DispatchOrder> order; // command owns the (possibly decorated) receiver chain
    Incident* incident;                   // non-owning
public:
    DispatchUnitCommand(std::unique_ptr<DispatchOrder> o, Incident* inc);
    void execute();
    void undo();
};
#endif
