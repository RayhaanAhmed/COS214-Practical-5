#include "SecurityTeam.h"
#include "StandardDispatch.h"

StandardDispatch::StandardDispatch(SecurityTeam* t)
{
    team = t;
}

void StandardDispatch::dispatch(Incident* incident)
{
    team->respondTo(incident);
}

std::string StandardDispatch::getBriefing() const
{
    return "Standard security response";
}