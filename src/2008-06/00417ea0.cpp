// from server: 100% by king_originala
struct Manager {
    virtual void slot0();
    virtual void slot1();
    virtual void release();
};

extern Manager* manager;
extern void* table0[];
extern void* table1[];
extern "C" void __cdecl freeObject(void*);

struct S {
    void* vptr0;
    void* vptr1;
    unsigned int state;

    void cleanup();
    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags)
{
    vptr0 = table0;
    vptr1 = table1;
    state = 0xC0000001u;
    manager->release();
    cleanup();
    if (flags & 1)
        freeObject(this);
    return this;
}
