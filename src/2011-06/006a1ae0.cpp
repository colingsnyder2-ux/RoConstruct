// from server: 58% by atomic.potato
struct S_func_008de100 {
    char pad0[36];
    int m_x;
    int f();
};

int S_func_008de100::f()
{
    return m_x;
}

struct S_func_006a1ae0 {
    int f();
};

int S_func_006a1ae0::f()
{
    S_func_008de100 *p = (S_func_008de100 *)((char *)this + 8);
    int v = p->f();
    if (v != 0) {
        v = ((S_func_008de100 *)v)->f();
        if (v != 0)
            return v - 8;
    }
    return 0;
}
