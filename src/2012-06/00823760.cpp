// from server: 53% by atomic.potato
struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

int* S_func_00750a60::f()
{
    return &m_x;
}

struct S {
    char pad0[4];
    void (__thiscall *m_fn)(int*);
    void __thiscall g(int* p);
};

void S::g(int* p)
{
    S_func_00750a60* obj;
    if (p != 0) {
        obj = (S_func_00750a60*)((char*)p - 0x1c);
    } else {
        obj = 0;
    }
    int* r = obj->f();
    m_fn(r + 2);
}
