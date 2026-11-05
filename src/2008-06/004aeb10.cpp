// from server: 100% by king_originala
struct BitStream {
    unsigned char storage[0x114];
    BitStream();
    ~BitStream();
};

struct Owner {
    unsigned char padding[0x2d54];
    unsigned low;
    unsigned high;
};

struct Peer {
#define SLOT(n) virtual void slot##n();
    SLOT(0)  SLOT(1)  SLOT(2)  SLOT(3)
    SLOT(4)  SLOT(5)  SLOT(6)  SLOT(7)
    SLOT(8)  SLOT(9)  SLOT(10) SLOT(11)
    SLOT(12) SLOT(13) SLOT(14) SLOT(15)
    SLOT(16) SLOT(17) SLOT(18) SLOT(19)
    SLOT(20) SLOT(21) SLOT(22) SLOT(23)
    SLOT(24) SLOT(25) SLOT(26) SLOT(27)
    SLOT(28) SLOT(29) SLOT(30) SLOT(31)
    SLOT(32) SLOT(33) SLOT(34) SLOT(35)
    SLOT(36) SLOT(37) SLOT(38) SLOT(39)
    SLOT(40) SLOT(41) SLOT(42) SLOT(43)
#undef SLOT
    virtual unsigned query(unsigned low, unsigned high);
};

struct State {
    unsigned char padding[0x148];
    unsigned time;
};

State* __cdecl getState();

struct S {
    Owner* owner;
    Peer* peer;
    BitStream stream;
    unsigned time;
    unsigned char flag;

    S(Owner* o, Peer* p);
};

S::S(Owner* o, Peer* p)
    : owner(o), peer(p)
{
    unsigned value = p->query(o->low, o->high);
    time = value - getState()->time;
    flag = 0;
}
