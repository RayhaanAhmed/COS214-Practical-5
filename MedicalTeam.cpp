#include "MedicalTeam.h"
#include <iostream>

MedicalTeam::MedicalTeam(const std::string& n)
 : ResponseComponent(n) { }

void MedicalTeam::standBy(Incident* incident) {
    std::cout << getName() << ": on standby for incident " << incident->getId() << ", ready to go in." << std::endl;
}