#ifndef ACCESS_CONTROL_SYSTEM_H
#define ACCESS_CONTROL_SYSTEM_H
#include "ResponseComponent.h"
#include <set>
#include <string>

class AccessControlSystem : public ResponseComponent {
private:
    std::set<std::string> lockedAreas;
public:
    AccessControlSystem(const std::string& n);
    bool lockArea(const std::string& area);
    bool unlockArea(const std::string& area);
    bool isLocked(const std::string& area) const;
};
#endif
