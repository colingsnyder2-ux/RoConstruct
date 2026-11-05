// from server: 27% by atomic.potato
struct S_func_0066c140 {
    char pad0[388];
    int m_x;
    int* f();
};

int* S_func_0066c140::f()
{
    return &m_x;
}

struct S {
    char pad0[4];
    void* m_fn;
    void g(void*);
};

void S::g(void* p)
{
    S_func_0066c140* obj;
    if (p) {
        obj = (S_func_0066c140*)((char*)p - 0x1c);
    } else {
        obj = 0;
    }
    int* r = obj->f();
    void* fn = m_fn;
    ((void (__thiscall*)(void*, int*))fn)(this, r);
}
