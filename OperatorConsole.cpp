#include "OperatorConsole.h"

OperatorConsole::~OperatorConsole() {
    for (Command* x : history) {
        delete x;
    }
    history.clear();
}

Command* OperatorConsole::submit(Command* cmd) {
    cmd->execute();
    history.push_back(cmd);
    return cmd;
}