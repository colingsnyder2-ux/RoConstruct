// from server: 43% by atomic.potato
extern "C" void __stdcall sub_006cbff0(void *, void *);

struct S
{
    int f();
};

int S::f()
{
    void *a = *(void **)((char *)this + 0x94);
    void *b = *(void **)((char *)this + 0x98);
    if (b)
        sub_006cbff0((void *)0x0066ed30, a);
    return 0;
}
