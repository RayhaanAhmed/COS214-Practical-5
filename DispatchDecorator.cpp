#include "DispatchDecorator.h"

DispatchDecorator::DispatchDecorator(std::unique_ptr<DispatchOrder> w)
{
    wrapped = std::move(w);
}

void DispatchDecorator::dispatch(Incident* incident)
{
    wrapped->dispatch(incident);
}

std::string DispatchDecorator::getBriefing() const
{
    if (wrapped == nullptr)
    {
        return "";
    }
    return wrapped->getBriefing();
}