// from server: 70% by atomic.potato
typedef unsigned int DWORD;

extern "C" void __cdecl sub_40bb20(void *);

struct S
{
    void *vtable;
    char data[36];
    DWORD field_28;
    char data2[16];
    DWORD field_3c;
    S *f(void *);
};

S *S::f(void *arg)
{
    S *self = this;
    sub_40bb20(arg);
    self->field_3c = 0x00A5BEE8;
    self->vtable = (void *)0x00A5C300;
    self->field_28 = 0x00A5C2F8;
    self->field_3c = 0x00A5C2E8;
    return self;
}
