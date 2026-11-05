// from server: 69% by atomic.potato
extern "C" void sub_411770(void *, void *);

struct S
{
    void *v0;
    char pad28[40];
    void *v28;
    char pad3c[20];
    void *v3c;
    S(void *);
};

S::S(void *p)
{
    sub_411770(this, p);
    v3c = (void *)0xA00920;
    v0 = (void *)0xA02D64;
    v28 = (void *)0xA02D5C;
    v3c = (void *)0xA02D4C;
}
