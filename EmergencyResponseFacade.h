#ifndef EMERGENCY_RESPONSE_FACADE_H
#define EMERGENCY_RESPONSE_FACADE_H

#include <string>
#include "Incident.h"
#include "OperatorConsole.h"
#include "AccessControlSystem.h"
#include "AlertChannel.h"
#include "DispatchOrder.h"

class EmergencyResponseFacade {
private:
    OperatorConsole* console;         // non-owning
    AccessControlSystem* access;      // non-owning
    AlertChannel* alertChannel;       // non-owning
public:
    EmergencyResponseFacade(OperatorConsole* c, AccessControlSystem* a, AlertChannel* al);

    // Coordinates >= 3 subsystem operations: dispatch, lockdown, alert - plus State transitions.
    // "type" is not branched on here (no switch/if-chain) - it is just data carried by Incident.
    void reportEmergency(Incident* incident, DispatchOrder* order, const std::string& alertMessage);
};
#endif
