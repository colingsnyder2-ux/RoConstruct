// from server: 100% by king_originala
struct Data
{
    unsigned int words[6];
};

extern bool __cdecl func_0060a2f0();
extern char marker;

struct S
{
    const void* tag;
    unsigned int reserved;
    Data data;

    void func_005b17d0(const Data& source);
};

void S::func_005b17d0(const Data& source)
{
    typedef bool (__cdecl *Predicate)(const Data&);
    if (!((Predicate)&func_0060a2f0)(source))
    {
        Data* destination = &data;
        if (destination)
            *destination = source;
        tag = &marker;
    }
    else
    {
        tag = 0;
    }
}
