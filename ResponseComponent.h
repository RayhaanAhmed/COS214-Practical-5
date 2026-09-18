#ifndef RESPONSE_COMPONENT_H
#define RESPONSE_COMPONENT_H
#include <string>
#include "IncidentMediator.h"

// Colleague (Mediator pattern)
class ResponseComponent {
protected:
    IncidentMediator* mediator; // non-owning back-reference
    std::string name;
public:
    ResponseComponent(const std::string& n) : mediator(nullptr), name(n) {}
    void setMediator(IncidentMediator* m) { mediator = m; }
    std::string getName() const { return name; }
    virtual ~ResponseComponent() {}
};
#endif
