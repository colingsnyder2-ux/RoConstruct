// from server: 100% by king_originala
extern int table0[];
extern int table4[];
extern int table8[];
extern int table20[];

struct Interface {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void release() = 0;
};

extern Interface* globalObject;
extern "C" void __cdecl deallocate(void*);

struct Part {
    int* table;
    int reserved[2];
    void destroy();
};

struct S {
    int* table0;
    int* table4;
    Part part;
    int* table20;
    unsigned int state;
    S* destroy(unsigned int flags);
};

S* S::destroy(unsigned int flags)
{
    this->table0 = ::table0;
    this->table4 = ::table4;
    part.table = table8;
    this->table20 = ::table20;
    state = 0xC0000001U;
    globalObject->release();
    part.destroy();
    if (flags & 1)
        deallocate(this);
    return this;
}
