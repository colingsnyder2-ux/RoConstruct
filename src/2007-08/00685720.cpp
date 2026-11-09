// from server: 100% by tajop
typedef int (__thiscall *Fn_00685720)(void*, int, int, int, int*);

struct O_00685720 { void* vtbl; };

int func_00685720(O_00685720* o, int a, int b, int c)
{
    return ((Fn_00685720*)o->vtbl)[0x58 / 4](o, a, 3, b, &c);
}
