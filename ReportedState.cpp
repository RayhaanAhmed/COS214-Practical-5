#include "ReportedState.h"
#include "Incident.h"

void ReportedState::handle(Incident* incident)
{
    std::cout << "Handling reported incident: " << incident->getId() << std::endl;
    incident->setState(std::make_unique<DispatchedState>());
}

bool ReportedState::canCancel() const
{
    return true;
}

std::string ReportedState::name() const
{
    return "Reported";
}