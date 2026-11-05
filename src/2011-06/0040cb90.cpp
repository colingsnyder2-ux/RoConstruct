// from server: 69% by atomic.potato
extern "C" void sub_40c040(void *, const char *);

struct S
{
    void *vtable;
    char padding_04[0x24];
    void *field_28;
    char padding_2c[0x0c];
    void *field_3c;
    S *f(const char *);
};

S *S::f(const char *message)
{
    sub_40c040(this, message);
    field_3c = (void *)0x00A5BEE8;
    vtable = (void *)0x00A5C294;
    field_28 = (void *)0x00A5C28C;
    field_3c = (void *)0x00A5C27C;
    return this;
}
