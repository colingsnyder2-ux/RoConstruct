// from server: 100% by king_originala
extern void* __cdecl getDescriptor();

struct Base {
    unsigned int words[7];

    Base(int argument);
    ~Base();
};

struct S : Base {
    void* descriptor;
    unsigned int slots[42];

    S(int argument);
};

S::S(int argument)
    : Base(argument), descriptor(getDescriptor())
{
    words[0] = 0x008317fc;
    words[4] = 0x008317ec;
    words[5] = 0x008317e4;
    slots[0] = 0x008317dc;
    slots[1] = 0x008317cc;
    slots[9] = 0x008317bc;
    slots[17] = 0x008317ac;
    slots[25] = 0x0083179c;
    slots[33] = 0x0083178c;
    slots[41] = 0x0083177c;
}
