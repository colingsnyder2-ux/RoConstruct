// from server: 100% by tajop
typedef int (__thiscall *Fn_00685700)(void*, int, int, int, int*);

struct O_00685700 { void* vtbl; };

int func_00685700(O_00685700* o, int a, int b, int c)
{
    return ((Fn_00685700*)o->vtbl)[0x58 / 4](o, a, 2, b, &c);
}
