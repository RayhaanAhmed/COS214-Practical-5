#ifndef SIREN_TOWER_ADAPTER_H
#define SIREN_TOWER_ADAPTER_H
#include "AlertChannel.h"
#include "SirenTower.h"

// Object Adapter: translates AlertChannel::send(message) into
// SirenTower::soundSiren(zoneCode, durationSecs). Composition, not
// multiple inheritance - see design notes for why.
class SirenTowerAdapter : public AlertChannel {
private:
    SirenTower* tower; // non-owning
public:
    SirenTowerAdapter(SirenTower* t);
    void send(const std::string& message);
};
#endif
