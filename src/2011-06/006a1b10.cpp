// from server: 72% by atomic.potato
struct S_func_006a1b10
{
};

void __cdecl f(void *a, void *b)
{
    if (b)
    {
        void **p = *(void ***)((char *)b + 0x1c);
        void (__thiscall *q)(void *, void *) =
            (void (__thiscall *)(void *, void *))p[1];
        q((void *)((char *)b + 0x1c), (void *)((char *)a + 0x1c));
    }
    else
    {
        void **p = *(void ***)0;
        void (__thiscall *q)(void *, void *) =
            (void (__thiscall *)(void *, void *))p[1];
        q((void *)0, (void *)((char *)a + 0x1c));
    }
}
