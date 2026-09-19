#include "EscalatedState.h"
#include "Incident.h"

void EscalatedState::handle(Incident* incident)
{
    std::cout << "Handling escalated incident: " << incident->getId() << std::endl;
    incident->setState(std::make_unique<ResolvedState>());
}

bool EscalatedState::canCancel() const
{
    return true;
}

std::string EscalatedState::name() const
{
    return "Escalated";
}