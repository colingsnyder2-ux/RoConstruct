// from server: 100% by king_originala
struct Service {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
};

extern Service* service;
extern void* objectTable[];
extern "C" void __cdecl releaseStorage(void*);

struct S {
    void** table;
    unsigned char reserved[20];
    unsigned long state;

    void cleanup();
    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags)
{
    table = objectTable;
    state = 0xC0000001UL;
    service->slot2();
    cleanup();
    if (flags & 1)
        releaseStorage(this);
    return this;
}
