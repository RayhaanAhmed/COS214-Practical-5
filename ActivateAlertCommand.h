#ifndef ACTIVATE_ALERT_COMMAND_H
#define ACTIVATE_ALERT_COMMAND_H
#include "Command.h"
#include <string>
using namespace std;

#include "AlertChannel.h";

class ActivateAlertCommand : public Command {
private:
    AlertChannel* receiver; //non-owning
    string message;
public:
    ActivateAlertCommand(AlertChannel* r, const string& m);
    void execute();
    void undo();
};
#endif
