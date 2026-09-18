#include "ResolvedState.h"
#include "Incident.h"

void ResolvedState::handle(Incident* incident)
{
    std::cout << "Incident has already been resolved: " << incident->getId() << std::endl;
}

bool ResolvedState::canCancel() const
{
    return false;
}

std::string ResolvedState::name() const
{
    return "Resolved";
}