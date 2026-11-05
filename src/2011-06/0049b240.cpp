// from server: 71% by atomic.potato
struct S
{
};

int __cdecl f(int a, int b)
{
    return ((int (__thiscall *)(int, int))(*(int *)a))(*(int *)(a + 4) + *(int *)(a + 8), b);
}
