#include "EmergencyResponseFacade.h"
#include "DispatchUnitCommand.h"
#include "LockdownAreaCommand.h"
#include "ActivateAlertCommand.h"
#include <iostream>

EmergencyResponseFacade::EmergencyResponseFacade(OperatorConsole* c,AccessControlSystem* a,AlertChannel* al) : console(c), access(a), alertChannel(al) {}

void EmergencyResponseFacade::reportEmergency(Incident* incident, DispatchOrder* order, const std::string& alertMessage){
    std::cout << "\nFACADE: reportEmergency for " << incident->getId()<< " (" << incident->getType() << ", severity " << incident->getSeverity()<< ") - status: " << incident->getStatusName() << std::endl;
    std::cout << "FACADE: dispatch briefing: " << order->getBriefing() << std::endl;
    //1.Dispatch (Command). The response components then coordinate through the Mediator.
    console->submit(new DispatchUnitCommand(order, incident));
    //2.Reported to Dispatched (State)
    incident->advance();
    //3.Containment: only lock down if nothing has locked the area yet
    if (!access->isLocked(incident->getLocation())) {
        console->submit(new LockdownAreaCommand(access, incident->getLocation()));
    }
    // 4. Alert (Command to AlertChannel, the channel may be the siren Adapter)
    console->submit(new ActivateAlertCommand(alertChannel, alertMessage));
    // 5. Dispatched to InProgress (State)
    incident->advance();
    std::cout << "FACADE: workflow complete: " << incident->getId() << " is now " << incident->getStatusName() << std::endl;
}

