// from server: 100% by king_originala
struct Service {
    virtual void first();
    virtual void second();
};

extern Service* service;

struct S {
    unsigned long table0;
    unsigned long table4;
    unsigned long table8;
    unsigned long paddingC;
    unsigned long table10;
    unsigned long padding14;
    unsigned long table18;
    unsigned long table1C;

    void prepare();
    S* initialize(int);
};

S* S::initialize(int)
{
    prepare();
    table0 = 0x0080AE6C;
    table4 = 0x0080AE58;
    table8 = 0x0080AE40;
    table10 = 0x0080AE24;
    table18 = 0x0080AE18;
    table1C = 0x0080AE0C;
    service->second();
    return this;
}
