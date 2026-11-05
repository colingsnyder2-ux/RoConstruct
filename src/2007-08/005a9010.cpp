// from server: 100% by colin
struct SignalTarget {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void fire(int value);
};

struct VHumanoid {
    char reserved[0x34];
    SignalTarget* target;
    void fireSignal();
};

void VHumanoid::fireSignal() {
    target->fire(1);
}
