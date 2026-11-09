// from server: 55% by atomic.potato
struct S_func_007e6cc0 {
    struct VTable {
        void (__thiscall *f58)(S_func_007e6cc0 *, void *, int);
    };
    char pad0[56];
    int m_38;
    VTable *vftable;
    void f(void *, void *);
};

void S_func_007e6cc0::f(void *a, void *b)
{
    if (m_38 == 0) {
        vftable->f58(this, b, 1);
        f(a, b);
    }
}
