#include "DispatchedState.h"
#include "Incident.h"

void DispatchedState::handle(Incident* incident)
{
    std::string incidentId = incident->getId();
    std::cout << "Handling dispatched incident: " << incidentId << std::endl;
    incident->setState(std::make_unique<InProgressState>());
}

bool DispatchedState::canCancel() const
{
    return true;
}

std::string DispatchedState::name() const
{
    return "Dispatched";
}