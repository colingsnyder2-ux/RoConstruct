// from server: 69% by atomic.potato
extern "C" void sub_411a70(void *, void *);

struct S
{
    int pad0[15];
    int field3c;
    int field40;
    int field44;
    int field48;
    int f(void *);
};

int S::f(void *arg)
{
    sub_411a70(this, arg);
    field3c = 0x99fd90;
    *(int *)this = 0x9a2148;
    *(int *)((char *)this + 0x28) = 0x9a2140;
    field3c = 0x9a2130;
    return (int)this;
}
