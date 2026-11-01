// from server: 100% by king_originala
struct Data
{
    unsigned int words[6];
};

extern bool __cdecl func_0060a2f0(const Data*);

struct S
{
    unsigned int tag;
    unsigned int padding;
    Data data;

    void __thiscall func_00618df0(const Data* source);
};

void S::func_00618df0(const Data* source)
{
    if (!func_0060a2f0(source))
    {
        Data* destination = &data;
        if (destination)
            *destination = *source;
        tag = 0x00843f48;
    }
    else
    {
        tag = 0;
    }
}
