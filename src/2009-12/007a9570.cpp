// from server: 77% by atomic.potato
extern "C" void __stdcall Call785A00(void *);

struct S
{
    int *vtable;
    int field04;
    int field08;
    int field0c;
    int field10;
    int field14;
    int field18;
    int field1c;
    int field20;

    S(void *);
};

S::S(void *arg)
{
    Call785A00(arg);
    vtable = (int *)0x9ed6bc;
    field04 = 0x9ed6a0;
    field1c = 0;
    field20 = 0;
}
