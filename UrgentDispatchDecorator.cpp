#include "UrgentDispatchDecorator.h"

UrgentDispatchDecorator::UrgentDispatchDecorator(std::unique_ptr<DispatchOrder> w)
    : DispatchDecorator(std::move(w)){}

void UrgentDispatchDecorator::dispatch(Incident* incident)
{
    wrapped->dispatch(incident);
}

std::string UrgentDispatchDecorator::getBriefing() const
{
    return "URGENT: " + wrapped->getBriefing();
}