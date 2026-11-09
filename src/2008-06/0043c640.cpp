// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct S {
    unsigned char padding0[0x118];
    void *buffer;
    unsigned char padding1[8];
    void *first;
    void *last;
    void *limit;

    void cleanup();
    S *destroy(unsigned int flags);
};

S *S::destroy(unsigned int flags)
{
    if (first)
        release(first);

    first = 0;
    last = 0;
    limit = 0;

    release(buffer);
    cleanup();

    if (flags & 1)
        release(this);

    return this;
}
