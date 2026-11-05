// from server: 69% by atomic.potato
struct S;

extern "C" void sub_005dbea0(const void *);

struct S {
    void *v0;
    char pad14[16];
    void *v28;
    S *f(const void *);
};

S *S::f(const void *p)
{
    sub_005dbea0(p);
    v28 = (void *)0x99fd90;
    v0 = (void *)0x9c1558;
    *(void **)((char *)this + 0x14) = (void *)0x9c1550;
    v28 = (void *)0x9c1540;
    return this;
}
