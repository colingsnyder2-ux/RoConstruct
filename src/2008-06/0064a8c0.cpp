// from server: 100% by king_originala
struct Base {
    virtual int slot0() = 0;
    virtual int slot1() = 0;
    virtual int slot2() = 0;
    virtual int slot3() = 0;
    virtual int slot4() = 0;
    virtual int slot5() = 0;
    virtual int get(int index) = 0;
};

struct SleepStage {
    char pad0[8];
    Base* base;
    char pad1[196];
    int value0;
    int value2;
    char pad2[204];
    int value1;

    int get(int index);
};

int SleepStage::get(int index)
{
    switch (index) {
    case 0: return value0;
    case 1: return value1;
    case 2: return value2;
    default: return base->get(index);
    }
}
