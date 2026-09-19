#include "ReportedState.h"
#include "Incident.h"
#include "DispatchedState.h"

void ReportedState::handle(Incident* incident)
{
    std::cout << "Handling reported incident: " << incident->getId() << std::endl;
    incident->setState(std::unique_ptr<IncidentState>(new DispatchedState()));
}

bool ReportedState::canCancel() const
{
    return true;
}

std::string ReportedState::name() const
{
    return "Reported";
}