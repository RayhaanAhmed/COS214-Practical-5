#include "Incident.h"
#include "IncidentState.h"
#include "ReportedState.h"

Incident::Incident(const std::string& id_, const std::string& type_, const std::string& location_, int severity_)
{
    id = id_;
    type = type_;
    location = location_;
    severity = severity_;
    state = std::unique_ptr<IncidentState>(new ReportedState());
}

void Incident::setState(std::unique_ptr<IncidentState> newState)
{
    state = std::move(newState);
}

void Incident::advance()
{
    state->handle(this);
}

bool Incident::canCancel() const
{
    return state->canCancel();
}

std::string Incident::getStatusName() const
{
    return state->name();
}