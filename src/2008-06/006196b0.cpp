// from server: 100% by king_originala
void* __cdecl getCreator();

struct Flag {
    unsigned long slots[0x71];
    Flag(int);
    ~Flag();
};

struct S : Flag {
    S(int complete);
};

S::S(int complete)
    : Flag(complete ? (slots[0x70] = 0x843de0, 0) : 0)
{
    slots[7] = reinterpret_cast<unsigned long>(getCreator());

    const int* table = reinterpret_cast<const int*>(slots[0x70]);
    slots[0] = 0x84403c;
    slots[4] = 0x844030;
    slots[5] = 0x844028;
    slots[8] = 0x844020;
    slots[9] = 0x844010;
    slots[0x11] = 0x844000;
    slots[0x19] = 0x843ff0;
    slots[0x21] = 0x843fe0;
    slots[0x29] = 0x843fd0;
    slots[0x31] = 0x843fc0;
    slots[0x4c] = 0x843fb8;
    slots[0x68] = 0x843fb0;
    slots[0x6c] = 0x843f98;

    *reinterpret_cast<unsigned long*>(
        reinterpret_cast<char*>(this) + 0x1c0 + table[1]) = 0x843f90;

    int offset = reinterpret_cast<const int*>(slots[0x70])[1];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(this) + 0x1bc + offset) = offset - 0xac;
}
