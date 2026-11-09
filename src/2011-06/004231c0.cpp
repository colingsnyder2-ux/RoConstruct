// from server: 76% by atomic.potato
extern "C" void sub_0080A856(void *, void *);

struct S
{
    int *vtable;
    char padding[232];
    int field_ec;
    int field_f0;
    S *f(void *);
};

S *S::f(void *arg)
{
    sub_0080A856(this, arg);
    vtable = (int *)0x00A6438C;
    field_ec = 0x00A64324;
    field_f0 = 0x00A64370;
    return this;
}
