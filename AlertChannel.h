#ifndef ALERT_CHANNEL_H
#define ALERT_CHANNEL_H
#include <string>

// Target (Adapter pattern) - also the Command receiver for ActivateAlertCommand
class AlertChannel {
public:
    virtual void send(const std::string& message) = 0;
    virtual ~AlertChannel() {}
};
#endif
