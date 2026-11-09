// from server: 100% by king_originala
struct Service
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void release() = 0;
};

struct Stream;

extern Service* service;
extern char table0[];
extern char table1[];
extern void (__thiscall *destroyStream)(Stream*);
void __cdecl operator delete(void*);

struct S
{
    void* vtable0;
    void* vtable1;
    unsigned long references;
    char stream[1];

    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags)
{
    vtable0 = table0;
    vtable1 = table1;
    references = 0xC0000001UL;
    service->release();
    destroyStream(reinterpret_cast<Stream*>(stream));
    if (flags & 1)
        operator delete(this);
    return this;
}
