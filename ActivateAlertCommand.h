#ifndef ACTIVATE_ALERT_COMMAND_H
#define ACTIVATE_ALERT_COMMAND_H
#include "Command.h"
#include <string>
class AlertChannel;

class ActivateAlertCommand : public Command {
private:
    AlertChannel* receiver; // non-owning
    std::string message;
public:
    ActivateAlertCommand(AlertChannel* r, const std::string& m);
    void execute();
    void undo();
};
#endif
