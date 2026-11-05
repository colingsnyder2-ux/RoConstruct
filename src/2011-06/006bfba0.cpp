// from server: 33% by atomic.potato
struct EventDesc {
    char pad0[4];
    void init(int);
    void fire(int, int);
};

void EventDesc::init(int)
{
    char pad[4];
    *(int*)pad = 0;
    void (*fn)(void*, int) = (void (*)(void*, int))0x4c1670;
    fn((char*)this + 4, 1);
}

void EventDesc::fire(int a, int b)
{
    void (*fn)(void*, int, int) = (void (*)(void*, int, int))0x4c13d0;
    fn(this, a, b);
}

int __stdcall EventDesc_ctor(EventDesc* self, int a, int b)
{
    self->init(0);
    self->fire(a, b);
    return a;
}
