#ifndef STANDARD_DISPATCH_H
#define STANDARD_DISPATCH_H
#include "DispatchOrder.h"
class SecurityTeam;

// ConcreteComponent
class StandardDispatch : public DispatchOrder {
private:
    SecurityTeam* team; // non-owning
public:
    StandardDispatch(SecurityTeam* t);
    void dispatch(Incident* incident);
    std::string getBriefing() const;
};
#endif
