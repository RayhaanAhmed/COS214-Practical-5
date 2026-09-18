#include "SirenTower.h"
#include <iostream>

void SirenTower::soundSiren(int zoneCode, int durationSecs){
    std::cout << "[SirenTower] Sounding siren: zone=" << zoneCode << " for " << durationSecs << " seconds" << std::endl;
}