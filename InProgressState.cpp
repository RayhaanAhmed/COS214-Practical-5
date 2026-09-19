#include "InProgressState.h"
#include "Incident.h"
#include "EscalatedState.h"

void InProgressState::handle(Incident* incident)
{
    std::cout << "Handling in-progress incident: " << incident->getId() << std::endl;
    incident->setState(std::unique_ptr<IncidentState>(new EscalatedState()));
}