// from server: 93% by atomic.potato
struct DirectPhysicsReceiver
{
    void __cdecl f(void *);
};

void __cdecl DirectPhysicsReceiver::f(void *p)
{
    int *ecx = p ? (int *)((char *)p + 0x30) : 0;
    int *edx = (int *)*ecx;
    int *eax = edx;

    if (*eax != (int)ecx)
    {
        do
        {
            eax = (int *)*eax;
        }
        while (*eax != (int)ecx);
    }

    *eax = (int)edx;
}
