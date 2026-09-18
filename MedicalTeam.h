#ifndef MEDICAL_TEAM_H
#define MEDICAL_TEAM_H
#include "ResponseComponent.h"

class MedicalTeam : public ResponseComponent {
public:
    MedicalTeam(const std::string& n);
    void standBy();
};
#endif
