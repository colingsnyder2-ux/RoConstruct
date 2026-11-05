// from server: 100% by atomic.potato
struct S_func_0066c140 {
    char pad0[388];
    int m_x;
    int* f();
};

struct S {
    char pad0[4];
    void (__thiscall *m_fn)(void*);
    void set(void* p);
};

void S::set(void* p)
{
    S_func_0066c140* obj;
    if (p) {
        obj = (S_func_0066c140*)((char*)p - 0x1c);
    } else {
        obj = 0;
    }
    int* r = obj->f();
    m_fn((char*)r + 0x28);
}
