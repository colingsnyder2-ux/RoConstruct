// from server: 100% by king_originala
struct Manager {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void release() = 0;
};

struct Interface {
    virtual void __stdcall slot0() = 0;
    virtual void __stdcall slot1() = 0;
    virtual unsigned long __stdcall release() = 0;
};

void __cdecl operator delete(void *);

struct S {
    unsigned long table0;
    unsigned long table4;
    unsigned long field8;
    unsigned long table12;
    Interface *field16;
    unsigned long table20;
    unsigned long field24;

    S *destroy(unsigned int flags);
};

S *S::destroy(unsigned int flags)
{
    table0 = 0x0080B58C;
    table4 = 0x0080B574;
    table12 = 0x0080B558;
    table20 = 0x0080B50C;
    field24 = 0xC0000001;

    (*(Manager **)0x0096C268)->release();

    if (field16)
        field16->release();

    if (flags & 1)
        operator delete(this);

    return this;
}
