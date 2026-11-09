// from server: 49% by atomic.potato
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
    void* m_vt;
    void g(void*);
};

void S::g(void* p)
{
    S_func_00750a60* obj;
    if (p)
        obj = (S_func_00750a60*)((char*)p - 0x1c);
    else
        obj = 0;
    int* r = obj->f();
    void (*fn)(void*) = *(void (**)(void*))((char*)this + 4);
    fn((char*)r + 0x18);
}
