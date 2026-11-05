// from server: 73% by atomic.potato
struct CInsertObjectDialog
{
    void *field18;
    int f(void *a, void *b, void *c);
};

extern "C" int __cdecl func_00419f60(int, int);

int CInsertObjectDialog::f(void *a, void *b, void *c)
{
    int x = ((int (__thiscall *)(void *))(*(int **)((char *)a + 0x18))[1])((char *)a + 0x18);
    int y = ((int (__thiscall *)(void *))(*(int **)((char *)b + 0x18))[1])((char *)b + 0x18);
    return func_00419f60(y, x);
}
