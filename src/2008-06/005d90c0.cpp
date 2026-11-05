// from server: 100% by atomic.potato
extern "C" int __cdecl call_5d8c10();

struct S
{
    int *f();
};

int *S::f()
{
    int *p = (int *)call_5d8c10();
    if (p)
        return (int *)((char *)p + 0x228);
    return 0;
}
