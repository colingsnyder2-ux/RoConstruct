// from server: 100% by king_originala
extern void __cdecl freeObject(void*);

struct S
{
    unsigned int table0;
    unsigned int table1;

    void cleanup();
    void* destroy(unsigned int flags);
};

void* S::destroy(unsigned int flags)
{
    table0 = 0x0084cce0;
    table1 = 0x0084ccd8;
    cleanup();
    if (flags & 1)
        freeObject(this);
    return this;
}
