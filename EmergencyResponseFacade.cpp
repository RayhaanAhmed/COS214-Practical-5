#include "EmergencyResponseFacade.h"
#include "Command.h"
#include <iostream>

EmergencyResponseFacade::EmergencyResponseFacade(OperatorConsole* c,AccessControlSystem* a,AlertChannel* al) : console(c), access(a), alertChannel(al) {}

void EmergencyResponseFacade::reportEmergency(Incident* incident, DispatchOrder* order, const std::string& alertMessage){
    std::cout << "\nFACADE: reportEmergency for " << incident->getId() << std::endl;
}

