// from server: 54% by atomic.potato
extern "C" int __stdcall sub_6f2da0(int);

struct S
{
    int f(int, int);
};

int S::f(int a, int b)
{
    int v = sub_6f2da0(b);
    void **p = *(void ***)((char *)this + 0x20);
    typedef int (__stdcall *Fn)(void *, int, int);
    return ((Fn)(*(void **)((char *)*p + 0x10)))(p, v, a);
}
