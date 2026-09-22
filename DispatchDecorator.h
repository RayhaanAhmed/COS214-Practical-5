#ifndef DISPATCH_DECORATOR_H
#define DISPATCH_DECORATOR_H
#include "DispatchOrder.h"
#include <memory>
#include <utility>

// Decorator (abstract)
class DispatchDecorator : public DispatchOrder {
protected:
    std::unique_ptr<DispatchOrder> wrapped; // owned by the decorator that wraps it
public:
    DispatchDecorator(std::unique_ptr<DispatchOrder> w);
    void dispatch(Incident* incident);
    std::string getBriefing() const;
};
#endif
