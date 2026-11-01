// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct S {
    unsigned long primary;
    unsigned long secondary;

    void cleanup();
    void *destroy(unsigned int flags);
};

void *S::destroy(unsigned int flags)
{
    primary = 0x843bd4;
    secondary = 0x843bbc;
    cleanup();
    if (flags & 1)
        release(this);
    return this;
}
