#include "DispatchUnitCommand.h"
#include <iostream>

DispatchUnitCommand::DispatchUnitCommand(DispatchOrder* o, Incident* inc)
 : order(o), incident(inc) { }

DispatchUnitCommand::~DispatchUnitCommand() {
    delete order;
    order = nullptr;
}

void DispatchUnitCommand::execute() {
    order->dispatch(incident);
}

void DispatchUnitCommand::undo() {   
    std::cout << "Recalling dispatch for incident " << incident->getId() << ": " << order->getBriefing() << std::endl;
}
