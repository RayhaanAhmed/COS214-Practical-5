#ifndef SIMPLE_ALERT_H
#define SIMPLE_ALERT_H
#include "AlertChannel.h"

// A plain, non-legacy alert channel (no adapter needed for this one).
class SimpleAlert : public AlertChannel {
public:
    void send(const std::string& message);
};
#endif
