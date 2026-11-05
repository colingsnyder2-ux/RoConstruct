// from server: 100% by tajop
typedef int (__thiscall *Fn_00685780)(void*, int, int, int, int*);

struct O_00685780 { void* vtbl; };

int func_00685780(O_00685780* o, int a, int b, int c)
{
    return ((Fn_00685780*)o->vtbl)[0x58 / 4](o, a, 0xb, b, &c);
}
