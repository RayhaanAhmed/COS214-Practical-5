#ifndef BACKUP_REQUEST_DECORATOR_H
#define BACKUP_REQUEST_DECORATOR_H
#include "DispatchDecorator.h"

class BackupRequestDecorator : public DispatchDecorator {
public:
    BackupRequestDecorator(std::unique_ptr<DispatchOrder> w);
    void dispatch(Incident* incident);
    std::string getBriefing() const;
};
#endif
