#include "LockdownAreaCommand.h"

LockdownAreaCommand::LockdownAreaCommand(AccessControlSystem* r, const std::string& a)
 : receiver(r), area(a) { }

void LockdownAreaCommand::execute() {
    if (!receiver->isLocked(area)) {
        receiver->lockArea(area);
    }
}

void LockdownAreaCommand::undo() {
  if (receiver->isLocked(area)) {
    receiver->unlockArea(area);
  }
}