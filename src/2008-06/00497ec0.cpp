// from server: 100% by king_originala
struct Net {
    virtual void v0();
    virtual void v1();
    virtual bool has(void*);
};

extern Net* net;
extern const char descriptor;

struct P {
    char padding[0x14];
    int addr;
};

struct Change {
    const void* descriptor;
};

struct Signal {
    char padding[0x50];
    void fire(unsigned int);
};

struct Players {
    char padding[0x150];
    Signal signal;
    P* player;

    void f(P*, const Change*);
};

void Players::f(P* p, const Change* change)
{
    if (p == player && change->descriptor == &descriptor) {
        if (player)
            reinterpret_cast<bool&>(p) = net->has(&player->addr);
        else
            reinterpret_cast<bool&>(p) = false;

        signal.fire(reinterpret_cast<unsigned int&>(p));
    }
}
