// from server: 100% by atomic.potato
struct S_func_00750a60 {
    char pad0[436];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void (__thiscall *m_fn)(void*);
    void g(void* p);
};

void S::g(void* p)
{
    S_func_00750a60* obj;
    if (p) {
        obj = (S_func_00750a60*)((char*)p - 0x1c);
    } else {
        obj = 0;
    }
    int* r = obj->f();
    m_fn((char*)r + 0x20);
}
