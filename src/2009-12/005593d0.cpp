// from server: 64% by atomic.potato
struct S
{
    int f(void *);
};

extern "C" int sub_519590(void *, void *);
extern "C" void sub_544820(void *);

int S::f(void *arg)
{
    void *p = *(void **)((char *)this + 0x2688);
    if (p != 0 && !sub_519590(p, arg))
        sub_544820(this);
    return 0;
}
