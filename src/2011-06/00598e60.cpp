// from server: 100% by atomic.potato
struct S {
};

void __cdecl f(void *p, double a, double b)
{
    if (*(int *)((char *)p + 0x10) != 0)
        (*(void (__thiscall **)(void *, double, double))(*(int **)((char *)p + 8)))((char *)p + 8, a, b);
}
