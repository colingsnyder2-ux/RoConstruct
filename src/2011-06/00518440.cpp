// from server: 93% by atomic.potato
struct S
{
    void __cdecl f(void *);
};

void __cdecl S::f(void *p)
{
    void **ecx;
    void **edx;
    void **eax;

    if (p)
        ecx = (void **)((char *)p + 0x70);
    else
        ecx = 0;

    edx = (void **)*ecx;
    eax = edx;

    if (*edx != ecx)
    {
        do
        {
            eax = (void **)*eax;
        } while (*eax != ecx);
    }

    *eax = edx;
}
