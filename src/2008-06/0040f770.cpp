// from server: 100% by king_originala
extern "C" void __cdecl release(void *);

struct Inner {
    unsigned int table;
    unsigned int reserved[2];
    void cleanup();
};

struct S {
    unsigned int table0;
    unsigned int table1;
    Inner inner;
    unsigned int table2;
    unsigned int state;

    S *destroy(unsigned int flags);
};

S *S::destroy(unsigned int flags)
{
    table0 = 0x0080D778;
    table1 = 0x0080D760;
    inner.table = 0x0080D73C;
    table2 = 0x0080D714;
    state = 0xC0000001;
    inner.cleanup();

    if (flags & 1)
        release(this);

    return this;
}
