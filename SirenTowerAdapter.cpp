#include "SirenTowerAdapter.h"
#include <iostream>

SirenTowerAdapter::SirenTowerAdapter(SirenTower* t) : tower(t) {}

void SirenTowerAdapter::send(const std::string& msg){
    int zone = 1;
    int duration = 30;
    if (msg.find("fire") != std::string::npos || msg.find("Fire") != std::string::npos) {
        zone = 2;
        duration = 60;
    }else if (msg.find("evac") != std::string::npos || msg.find("Evac") != std::string::npos) {
        zone = 3;
        duration = 45;
    }
    std::cout << "[Adapter] Translating message " << msg << " -> zone " << zone << ", duration " << duration << std::endl;
    tower->soundSiren(zone, duration);
}