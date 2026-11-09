// from server: 100% by atomic.potato
struct S;

extern "C" void sub_442cd0();

struct S {
    void *vtable;
    void *field04;
    char padding[16];
    void *field18;
    void *field1c;
    char padding2[116];
    int field94;
    S();
};

S::S()
{
    sub_442cd0();
    vtable = (void *)0x009a9fc4;
    field04 = (void *)0x009a9fb8;
    field18 = (void *)0x009a9fac;
    field1c = (void *)0x009a9fa4;
    field94 = 0;
}
