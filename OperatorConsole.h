#ifndef OPERATOR_CONSOLE_H
#define OPERATOR_CONSOLE_H
#include <vector>
#include <memory>
class Command;

// Invoker
class OperatorConsole {
private:
    std::vector<std::unique_ptr<Command>> history; // owns submitted commands
public:
    Command* submit(std::unique_ptr<Command> cmd); // executes, keeps for possible cancel/undo
};
#endif
