// from server: 100% by king_originala
struct Value
{
    unsigned int words[4];
};

struct Argument
{
    Value value;
    unsigned int extra;
};

extern "C" bool __cdecl func_0060a2f0();
extern unsigned char marker;

inline void* __cdecl operator new(unsigned int, void* p)
{
    return p;
}

struct S
{
    void* tag;
    unsigned int reserved;
    Value value;

    S* f(Argument argument);
};

S* S::f(Argument argument)
{
    tag = 0;
    if (!((bool (__cdecl *)(const Argument*))func_0060a2f0)(&argument))
    {
        new (&value) Value(argument.value);
        tag = &marker;
    }
    else
    {
        tag = 0;
    }
    return this;
}
