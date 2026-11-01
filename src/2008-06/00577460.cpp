// from server: 100% by king_originala
struct Event {
    void fire(int*);
};

struct Receiver {
    char padding[0x344];
    Event event;
};

struct State {
    char padding[0x1b4];
    int mode;
};

struct S {
    char padding0[0x204];
    Receiver* receiver;
    char padding1[4];
    State* state;
    char padding2[0x49];
    bool enabled;

    void update(int*);
    void f(int*);
};

void S::f(int* p)
{
    if (enabled) {
        if (*p != 0)
            update(p);

        switch (state->mode) {
        case 1:
            break;
        default:
            reinterpret_cast<unsigned char*>(&p)[0] = 0;
            receiver->event.fire(p);
            break;
        }
    }
}
