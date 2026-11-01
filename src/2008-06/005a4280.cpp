// from server: 100% by king_originala
unsigned long __cdecl getValue();

struct ConstructionState
{
    volatile int value;
    ConstructionState();
};

__forceinline ConstructionState::ConstructionState() : value(0)
{
}

struct Base
{
    unsigned long data[193];
    Base(int);
    ~Base();
};

struct S : Base
{
    S(int initialize);
};

S::S(int initialize)
    : Base((ConstructionState(), initialize
        ? (data[0x134 / 4] = 0x00831e28,
           data[0x300 / 4] = 0x00846144, 0)
        : 0))
{
    data[0x1c / 4] = getValue();

    unsigned long* table =
        reinterpret_cast<unsigned long*>(data[0x134 / 4]);

    data[0x000 / 4] = 0x00833d94;
    data[0x010 / 4] = 0x00833d88;
    data[0x014 / 4] = 0x00833d80;
    data[0x020 / 4] = 0x00833d78;
    data[0x024 / 4] = 0x00833d68;
    data[0x044 / 4] = 0x00833d58;
    data[0x064 / 4] = 0x00833d48;
    data[0x084 / 4] = 0x00833d38;
    data[0x0a4 / 4] = 0x00833d28;
    data[0x0c4 / 4] = 0x00833d18;
    data[0x130 / 4] = 0x00833d0c;
    data[0x1a0 / 4] = 0x00833cf4;
    data[0x288 / 4] = 0x00833cdc;

    *reinterpret_cast<unsigned long*>(
        reinterpret_cast<char*>(this) + 0x134 + table[1]) = 0x00833cd0;

    table = reinterpret_cast<unsigned long*>(data[0x134 / 4]);
    *reinterpret_cast<unsigned long*>(
        reinterpret_cast<char*>(this) + 0x134 + table[2]) = 0x00833cc8;

    table = reinterpret_cast<unsigned long*>(data[0x134 / 4]);
    *reinterpret_cast<unsigned long*>(
        reinterpret_cast<char*>(this) + 0x134 + table[3]) = 0x00833cac;

    table = reinterpret_cast<unsigned long*>(data[0x134 / 4]);
    unsigned long offset = table[1];
    *reinterpret_cast<unsigned long*>(
        reinterpret_cast<char*>(this) + 0x130 + offset) = offset - 0x1b8;

    table = reinterpret_cast<unsigned long*>(data[0x134 / 4]);
    offset = table[2];
    *reinterpret_cast<unsigned long*>(
        reinterpret_cast<char*>(this) + 0x130 + offset) = offset - 0x1c0;

    table = reinterpret_cast<unsigned long*>(data[0x134 / 4]);
    offset = table[3];
    *reinterpret_cast<unsigned long*>(
        reinterpret_cast<char*>(this) + 0x130 + offset) = offset - 0x1c8;
}
