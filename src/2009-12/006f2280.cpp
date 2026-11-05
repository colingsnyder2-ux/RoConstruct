// from server: 53% by atomic.potato
struct S_func_006cb2b0 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_006cb2b0::f()
{
    return &m_x;
}

struct S {
    char pad0[4];
    void (__thiscall *m_fn)(int*);
    void __thiscall method(int* arg);
};

void S::method(int* arg)
{
    S_func_006cb2b0* p;
    if (arg != 0) {
        p = (S_func_006cb2b0*)((char*)arg - 0x1c);
    } else {
        p = 0;
    }
    int* r = p->f();
    m_fn(r + 4);
}
