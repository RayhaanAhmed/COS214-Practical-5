#ifndef FACILITIES_TEAM_H
#define FACILITIES_TEAM_H
#include "ResponseComponent.h"
#include <string>

class FacilitiesTeam : public ResponseComponent {
public:
    FacilitiesTeam(const std::string& n);
    void assistWithArea(const std::string& area);
};
#endif
