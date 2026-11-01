// from server: 100% by king_originala
struct Interface
{
    virtual void slot0() = 0;
    virtual void slot1() = 0;
};

struct S
{
    unsigned int table0;
    unsigned int table4;
    volatile unsigned int table8;
    unsigned int valueC;
    unsigned int value10;
    unsigned int table14;
    unsigned int value18;
    volatile unsigned short value1C;

    S* initialize(int);
};

S* S::initialize(int)
{
    value18 = 0;
    value10 = 0;
    valueC = 0;
    table8 = 0x80D388;
    value1C = 0;
    table0 = 0x80D638;
    table4 = 0x80D620;
    table8 = 0x80D5FC;
    table14 = 0x80D5D4;
    (*(Interface**)0x96C268)->slot1();
    return this;
}
