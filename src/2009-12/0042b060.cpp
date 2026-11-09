// from server: 96% by atomic.potato
extern "C" void __cdecl Call90F222(int);
extern "C" void __cdecl Call7F385A(void *);

struct S
{
};

void __cdecl f(void *p)
{
    if (p)
    {
        Call90F222(*(int *)p);
        Call7F385A(p);
    }
}
