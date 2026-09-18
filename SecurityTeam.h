#ifndef SECURITY_TEAM_H
#define SECURITY_TEAM_H
#include "ResponseComponent.h"
class Incident;

class SecurityTeam : public ResponseComponent {
public:
    SecurityTeam(const std::string& n);
    void respondTo(Incident* incident);
};
#endif
