// from server: 100% by king_originala
extern void __cdecl release(void*);

struct S
{
    unsigned long table0;
    unsigned long table1;

    void cleanup();
    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags)
{
    table0 = 0x0084CC38;
    table1 = 0x0084CC30;
    cleanup();
    if (flags & 1)
        release(this);
    return this;
}
