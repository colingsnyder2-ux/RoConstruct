// from server: 92% by atomic.potato
struct S
{
    int f();
};

extern "C" int __cdecl G1_func_0080b2ea(int, const void *, int, int, int);

int S::f()
{
    int value = G1_func_0080b2ea(*(int *)((char *)this + 0x44), 0, (int)0xc071f8, (int)0xc12ef0, 0);
    if (value != 0)
    {
        struct VTable
        {
            void *entries[24];
        };
        return ((int (__thiscall *)(void *))((VTable *)*(void **)value)->entries[23])((void *)value);
    }
    return 0;
}
