#include "EscalatedState.h"
#include "Incident.h"
#include "ResolvedState.h"

void EscalatedState::handle(Incident* incident)
{
    std::cout << "Handling escalated incident: " << incident->getId() << std::endl;
    incident->setState(std::unique_ptr<IncidentState>(new ResolvedState()));
}

bool EscalatedState::canCancel() const
{
    return true;
}

std::string EscalatedState::name() const
{
    return "Escalated";
}