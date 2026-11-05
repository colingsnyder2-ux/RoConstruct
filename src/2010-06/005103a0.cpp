// from server: 96% by atomic.potato
struct S
{
};

void __cdecl f(void *p)
{
    void *ecx;
    void *edx;
    void *eax;

    if (p)
        ecx = (char *)p + 0x30;
    else
        ecx = 0;

    edx = *(void **)ecx;
    eax = edx;

    while (*(void **)eax != ecx)
        eax = *(void **)eax;

    *(void **)eax = edx;
}
