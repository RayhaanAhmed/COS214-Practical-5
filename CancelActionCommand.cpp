#include "CancelActionCommand.h"

CancelActionCommand::CancelActionCommand(Incident* inc, Command* t) 
 : incident(inc), target(t) { }

void CancelActionCommand::execute() {
   if (incident->canCancel()) {
      target->undo();
   } else {
      cout << "Cannot cancel: incident " << incident->getId() << " is in a state that does not allow cancellation ("
           << incident->getStatusName() << ")" << endl;
   }
}

void CancelActionCommand::undo() {
    if (incident->canCancel()) {
        target->execute();
    }
}