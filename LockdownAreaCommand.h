#ifndef LOCKDOWN_AREA_COMMAND_H
#define LOCKDOWN_AREA_COMMAND_H
#include "Command.h"
#include <string>
class AccessControlSystem;

class LockdownAreaCommand : public Command {
private:
    AccessControlSystem* receiver; // non-owning
    std::string area;
public:
    LockdownAreaCommand(AccessControlSystem* r, const std::string& a);
    void execute();
    void undo();
};
#endif
