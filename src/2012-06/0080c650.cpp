// from server: 48% by atomic.potato
struct S_func_0080c650 {
    void f();
};

void S_func_0080c650::f()
{
    void (*p)();
    void (__thiscall *q)(S_func_0080c650 *, const char *);

    p = (void (*)())0x7ebac0;
    q = (void (__thiscall *)(S_func_0080c650 *, const char *))0x414da0;

    p();
    q(this, (const char *)0xe4fde0);
    q(this, (const char *)0xe4fd2c);
}
