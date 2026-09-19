#include "ActivateAlertCommand.h"

ActivateAlertCommand::ActivateAlertCommand(AlertChannel* r, const string& m) 
: receiver(r), message(m) { }

void ActivateAlertCommand::execute() {
    receiver->send(message);
}

void ActivateAlertCommand::undo() {
    receiver->send("CORRECTION: Previous alert cancelled - " + message);
}