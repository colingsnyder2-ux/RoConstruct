// from server: 69% by atomic.potato
extern "C" void sub_409990(void *, const void *);

struct S
{
    void *vtable;
    char pad04[8];
    void *field0c;
    char pad10[16];
    void *field20;
    S *f(const void *);
};

S *S::f(const void *arg)
{
    sub_409990(this, arg);
    field20 = (void *)0x00a00b28;
    vtable = (void *)0x00a00b40;
    field0c = (void *)0x00a00b38;
    field20 = (void *)0x00a00b28;
    return this;
}
