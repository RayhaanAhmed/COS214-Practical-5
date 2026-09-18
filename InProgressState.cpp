#include "InProgressState.h"
#include "Incident.h"

void InProgressState::handle(Incident* incident)
{
    std::cout << "Handling in-progress incident: " << incident->getId() << std::endl;
    incident->setState(std::make_unique<EscalatedState>());
}

bool InProgressState::canCancel() const
{
    return false;
}

std::string InProgressState::name() const
{
    return "InProgress";
}