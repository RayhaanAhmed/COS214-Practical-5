#ifndef URGENT_DISPATCH_DECORATOR_H
#define URGENT_DISPATCH_DECORATOR_H
#include "DispatchDecorator.h"

class UrgentDispatchDecorator : public DispatchDecorator {
public:
    UrgentDispatchDecorator(std::unique_ptr<DispatchOrder> w);
    void dispatch(Incident* incident);
    std::string getBriefing() const;
};
#endif
