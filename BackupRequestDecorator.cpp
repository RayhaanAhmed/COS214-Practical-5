#include "BackupRequestDecorator.h"

BackupRequestDecorator::BackupRequestDecorator(std::unique_ptr<DispatchOrder> w)
    : DispatchDecorator(std::move(w)){}

void BackupRequestDecorator::dispatch(Incident* incident)
{
    wrapped->dispatch(incident);
}

std::string BackupRequestDecorator::getBriefing() const
{
    return "BACKUP REQUESTED: " + wrapped->getBriefing();
}