// from server: 100% by king_originala
extern unsigned int __cdecl getType();

struct S
{
    unsigned int data[257];
    void base(int);
    ~S();
    S* f(int);
};

struct Cleanup
{
    S* object;
    Cleanup(S*, int);
    ~Cleanup();
};

inline Cleanup::Cleanup(S* p, int initialize) : object(p)
{
    volatile int state = 0;
    if (initialize)
    {
        p->data[0x134 / 4] = 0x849e6c;
        p->data[0x400 / 4] = 0x846144;
    }
    p->base(0);
}

inline Cleanup::~Cleanup()
{
    if (object)
        object->~S();
}

S* S::f(int initialize)
{
    Cleanup cleanup(this, initialize);
    data[0x1c / 4] = getType();
    data[0] = 0x846354;
    data[0x10 / 4] = 0x846344;
    data[0x14 / 4] = 0x84633c;
    data[0x20 / 4] = 0x846334;
    data[0x24 / 4] = 0x846324;
    data[0x44 / 4] = 0x846314;
    data[0x64 / 4] = 0x846304;
    data[0x84 / 4] = 0x8462f4;
    data[0xa4 / 4] = 0x8462e4;
    data[0xc4 / 4] = 0x8462d4;
    data[0x130 / 4] = 0x8462c8;
    data[0x1a0 / 4] = 0x8462b8;
    data[0x1c0 / 4] = 0x8462ac;
    data[0x1cc / 4] = 0x846294;

    *(unsigned int*)((char*)this + 0x134 +
        ((int*)data[0x134 / 4])[1]) = 0x846288;
    *(unsigned int*)((char*)this + 0x134 +
        ((int*)data[0x134 / 4])[2]) = 0x846280;
    *(unsigned int*)((char*)this + 0x134 +
        ((int*)data[0x134 / 4])[3]) = 0x846264;

    int offset = ((int*)data[0x134 / 4])[1];
    *(int*)((char*)this + 0x130 + offset) = offset - 0x2b8;
    offset = ((int*)data[0x134 / 4])[2];
    *(int*)((char*)this + 0x130 + offset) = offset - 0x2c0;
    offset = ((int*)data[0x134 / 4])[3];
    *(int*)((char*)this + 0x130 + offset) = offset - 0x2c8;

    cleanup.object = 0;
    return this;
}
