#ifndef SIREN_TOWER_H
#define SIREN_TOWER_H

// Adaptee: an existing campus siren tower system, bought from an outdoor-
// warning-system vendor. Its control interface is fixed by the vendor and
// CampusGuard cannot change it: it takes a zone number and a duration in
// seconds, not a free-text message. This is the incompatible interface
// AlertChannel needs adapting to.
class SirenTower {
public:
    void soundSiren(int zoneCode, int durationSecs);
};
#endif
