#ifndef OPERATOR_CONSOLE_H
#define OPERATOR_CONSOLE_H
#include <vector>

#include "Command.h"

// Invoker
class OperatorConsole {
private:
    std::vector<Command*> history; // owns submitted commands
public:

    Command* submit(Command* cmd); //executes, keeps for possible cancel/undo
    ~OperatorConsole();
};
#endif
