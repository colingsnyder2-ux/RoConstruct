// from server: 100% by tajop
typedef int (__thiscall *Fn_00685840)(void*, int, int, int, int*);

struct O_00685840 { void* vtbl; };

int func_00685840(O_00685840* o, int a, int b, int c)
{
    return ((Fn_00685840*)o->vtbl)[0x58 / 4](o, a, 0x64, b, &c);
}
