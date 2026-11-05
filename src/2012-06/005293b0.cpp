// from server: 90% by atomic.potato
struct S
{
    int *vftable;
    int field4;
    int field8;
    int fieldc;
    int field10;
    int field14;
    int field18;
    int field1c;

    void f();
};

void S::f()
{
    vftable = (int *)0xB6FBAC;
    field4 = (int)0xB6FBA0;
    field18 = (int)0xB6FB94;
    field1c = (int)0xB6FB88;
}
