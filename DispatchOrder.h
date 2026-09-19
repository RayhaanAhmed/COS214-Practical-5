#ifndef DISPATCH_ORDER_H
#define DISPATCH_ORDER_H
#include <string>
class Incident;

// Component (Decorator pattern) - also the Command receiver for DispatchUnitCommand
class DispatchOrder {
public:
    virtual void dispatch(Incident* incident) = 0;
    virtual std::string getBriefing() const = 0;
    virtual ~DispatchOrder();
};
#endif
