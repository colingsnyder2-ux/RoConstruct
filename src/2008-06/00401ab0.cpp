// from server: 100% by king_originala
extern void G1_func_0046b740();

struct Interface {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
};

struct S {
    unsigned long field00;
    unsigned long field04;
    unsigned long field08;
    unsigned long field0C;
    unsigned long field10;
    unsigned long field14;
    unsigned long field18;
    unsigned long field1C;
    unsigned long field20;

    void f();
    void finish();
};

void S::f()
{
    field00 = 0x0080AE6C;
    field04 = 0x0080AE58;
    field08 = 0x0080AE40;
    field10 = 0x0080AE24;
    field18 = 0x0080AE18;
    field1C = 0x0080AE0C;
    field20 = 0xC0000001;
    G1_func_0046b740();
    (*(Interface **)0x0096C268)->slot2();
    finish();
}
