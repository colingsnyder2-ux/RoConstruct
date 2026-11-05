// from server: 100% by Yeetserama
typedef int (__thiscall *Fn_006856e0)(void*, int, int, int, int*);

struct O_006856e0 { void* vtbl; };

int func_006856e0(O_006856e0* o, int a, int b, int c)
{
    return ((Fn_006856e0*)o->vtbl)[0x58 / 4](o, a, 0x65, b, &c);
}
