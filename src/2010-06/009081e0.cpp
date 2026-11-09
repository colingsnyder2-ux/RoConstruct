// from server: 55% by atomic.potato
struct S_func_009081e0 {
    char pad0[8];
    S_func_009081e0* next;
    char pad1[81];
    char flag;
    S_func_009081e0* f();
};

S_func_009081e0* S_func_009081e0::f()
{
    S_func_009081e0* p = next;
    while (!p->flag)
        p = p->next;
    return p;
}
