// from server: 48% by atomic.potato
extern "C" void* __cdecl sub_98211a(unsigned int size);

struct EventDesc {
    int f0;
    int f4;
    int f8;
    char pad[0x60];
    char f6c;
    char f6d;
};

EventDesc* __cdecl make_EventDesc()
{
    EventDesc* p = (EventDesc*)sub_98211a(0x70);
    if (p)
        p->f0 = 0;
    if (p)
        p->f4 = 0;
    if (p)
        p->f8 = 0;
    p->f6c = 1;
    p->f6d = 0;
    return p;
}
