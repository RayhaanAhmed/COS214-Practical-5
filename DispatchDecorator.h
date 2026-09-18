#ifndef DISPATCH_DECORATOR_H
#define DISPATCH_DECORATOR_H
#include "DispatchOrder.h"
#include <memory>

// Decorator (abstract)
class DispatchDecorator : public DispatchOrder {
protected:
    std::unique_ptr<DispatchOrder> wrapped; // owned by the decorator that wraps it
public:
    DispatchDecorator(std::unique_ptr<DispatchOrder> w) : wrapped(std::move(w)) {}
    void dispatch(Incident* incident) { wrapped->dispatch(incident); }
    std::string getBriefing() const { return wrapped->getBriefing(); }
};
#endif
