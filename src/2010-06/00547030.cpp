// from server: 54% by atomic.potato
struct S_00547030 {
    char pad0[16];
    void* m_ptr;
    int f(void** a, void* b);
};

int S_00547030::f(void** a, void* b)
{
    void* p = m_ptr;
    if (p == 0) {
        *a = p;
        return 0;
    }
    typedef void (__thiscall *Fn)(void*, void*, void*);
    Fn fn = *(Fn*)((char*)*(void**)p + 0x24);
    fn(p, a, b);
    return (int)a;
}
