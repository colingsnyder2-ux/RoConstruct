// from server: 100% by atomic.potato
extern "C" void __cdecl Function_0090e980(void *, int);
extern "C" void __cdecl Function_00982114(void *);

struct S
{
};

void __cdecl f(void *p)
{
    if (p)
    {
        Function_0090e980(p, *(int *)((char *)p + 12));
        Function_00982114(p);
    }
}
