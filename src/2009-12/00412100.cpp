// from server: 69% by atomic.potato
struct S;

extern "C" void sub_411950(S *, void *);

struct S
{
    int pad0[10];
    void *field28;
    int pad2c[3];
    void *field3c;
    S(void *);
};

S::S(void *arg)
{
    sub_411950(this, arg);
    field3c = (void *)0x0099fd90;
    field28 = (void *)0x009a20f8;
    field3c = (void *)0x009a20e8;
    *(void **)this = (void *)0x009a2100;
}
