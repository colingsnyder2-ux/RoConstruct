#pragma once
// INFERRED: stub for missing v8world/Mechanism.h; used as const Mechanism* / Mechanism& in Replicator::JobSender
// MechanismTracker is a small tracker object used by value (Replicator.h line 215)
class Mechanism {
public:
    Mechanism();
    ~Mechanism();
};

class MechanismTracker {
public:
    MechanismTracker(const Mechanism* mechanism = NULL);
    ~MechanismTracker();
    void stopTracking();
    void setMechanism(const Mechanism* mechanism);
    void transferTrackers(MechanismTracker& other);
private:
    const Mechanism* mechanism;
};
