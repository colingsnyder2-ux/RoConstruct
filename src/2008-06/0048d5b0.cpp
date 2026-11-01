// from server: 100% by king_originala
struct Control
{
    long reserved;
    volatile long references;
};

struct Shared
{
    long object;
    Control* control;
    void destroy();
};

struct S
{
    long a;
    long b;
    Control* c;
    void copy(const S* source);
};

typedef bool (__thiscall *TypeEqual)(const void*, const void*);
extern TypeEqual typeEqual;
extern const char targetType;

void __cdecl reconstruct(S* source, S* destination, int operation)
{
    if (operation == 0)
    {
        if (destination)
            destination->copy(source);
    }
    else if (operation == 1)
    {
        reinterpret_cast<Shared*>(
            reinterpret_cast<char*>(destination) + 4)->destroy();
    }
    else
    {
        const void** slot = reinterpret_cast<const void**>(destination);
        *slot = typeEqual(*slot, &targetType) ? source : 0;
    }
}
