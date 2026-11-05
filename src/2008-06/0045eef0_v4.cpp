// from server: 88% by king_originala
bool __cdecl func_0060a2f0();

extern const unsigned table00;
extern const unsigned table10;
extern const unsigned table14;
extern const unsigned table20;
extern const unsigned table24;
extern const unsigned table44;
extern const unsigned table64;
extern const unsigned table84;
extern const unsigned tableA4;
extern const unsigned tableC4;
extern const unsigned pairTable;

struct Pair
{
    const char *first;
    unsigned second;
};

struct S
{
    unsigned data[90];

    void initialize();
    S *construct(unsigned value);
};

S *S::construct(unsigned value)
{
    initialize();

    Pair p;
    p.first = "Minor";
    Pair *pp = &p;
    p.second = value;

    data[0x00 / 4] = reinterpret_cast<unsigned>(&table00);
    data[0x10 / 4] = reinterpret_cast<unsigned>(&table10);
    data[0x14 / 4] = reinterpret_cast<unsigned>(&table14);
    data[0x20 / 4] = reinterpret_cast<unsigned>(&table20);
    data[0x24 / 4] = reinterpret_cast<unsigned>(&table24);
    data[0x44 / 4] = reinterpret_cast<unsigned>(&table44);
    data[0x64 / 4] = reinterpret_cast<unsigned>(&table64);
    data[0x84 / 4] = reinterpret_cast<unsigned>(&table84);
    data[0xa4 / 4] = reinterpret_cast<unsigned>(&tableA4);
    data[0xc4 / 4] = reinterpret_cast<unsigned>(&tableC4);
    data[0x158 / 4] = 0;

    if (!reinterpret_cast<bool (__cdecl *)(Pair *)>(
            func_0060a2f0)(pp))
    {
        Pair *destination = reinterpret_cast<Pair *>(&data[0x160 / 4]);
        if (destination)
            *destination = p;
        data[0x158 / 4] = reinterpret_cast<unsigned>(&pairTable);
        return this;
    }

    data[0x158 / 4] = 0;
    return this;
}