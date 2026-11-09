// from server: 100% by king_originala
struct Interface
{
    unsigned long (__stdcall **vtable)(Interface*);
};

extern void __cdecl freeObject(void*);

struct S
{
    char padding[16];
    Interface* object;

    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags)
{
    Interface* p = object;
    if (p)
        p->vtable[2](p);

    if (flags & 1)
        freeObject(this);

    return this;
}
