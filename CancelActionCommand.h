#ifndef CANCEL_ACTION_COMMAND_H
#define CANCEL_ACTION_COMMAND_H
#include "Command.h"
class Incident;

class CancelActionCommand : public Command {
private:
    Incident* incident;  // non-owning
    Command* target;     // non-owning: the previously-executed command to undo
public:
    CancelActionCommand(Incident* inc, Command* t);
    void execute();
    void undo();
};
#endif
