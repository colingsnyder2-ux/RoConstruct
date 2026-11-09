// from server: 95% by atomic.potato
struct S_func_008ff780;

typedef char *(__thiscall *Fn_008ff790)(S_func_008ff780 *, int);

struct S_func_008ff780
{
    Fn_008ff790 *vtable;

    int f();
};

int S_func_008ff780::f()
{
    if (vtable[4](this, 0)[16] && vtable[4](this, 1)[16])
        return 1;
    return 0;
}
