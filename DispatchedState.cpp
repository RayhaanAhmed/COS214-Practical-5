#include "DispatchedState.h"
#include "Incident.h"
#include "InProgressState.h"

void DispatchedState::handle(Incident* incident)
{
    std::string incidentId = incident->getId();
    std::cout << "Handling dispatched incident: " << incidentId << std::endl;
    incident->setState(std::unique_ptr<IncidentState>(new InProgressState()));
}