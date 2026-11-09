// from server: 100% by king_originala
struct Base {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void set(int index, int value, bool enabled, bool reset) = 0;
};

struct SleepStage {
    char pad0[8];
    Base* base;
    char pad1[204];
    bool enabled;
    char pad2[3];
    int value;

    void reset();
    void update(int index);
    void set(int index, int newValue, bool newEnabled, bool doReset);
};

void SleepStage::set(int index, int newValue, bool newEnabled, bool doReset)
{
    enabled = newEnabled;
    value = newValue;
    if (doReset)
        reset();
    else
        update(index);
    base->set(index, value, enabled, doReset);
}
