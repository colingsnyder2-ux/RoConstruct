// from server: 100% by atomic.potato
struct S_func_00636ea0 {
    char pad0[388];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void (__thiscall *m_fn)(int*);
    void __thiscall g(int* p);
};

void S::g(int* p)
{
    S_func_00636ea0* o;
    if (p) {
        o = (S_func_00636ea0*)((char*)p - 0x1c);
    } else {
        o = 0;
    }
    int* r = o->f();
    m_fn(r + 6);
}
