// from server: 100% by atomic.potato
struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void (__thiscall *m_cb)(void*);
    void __thiscall set(void* p);
};

void __thiscall S::set(void* p)
{
    S_func_00750a60* o;
    if (p) {
        o = (S_func_00750a60*)((char*)p - 0x1c);
    } else {
        o = 0;
    }
    int* q = o->f();
    m_cb((char*)q + 0x10);
}
