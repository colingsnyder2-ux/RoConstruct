// from server: 100% by why2
struct S_func_0067e3d0 {
    char pad[0x24];
    void* m_ptr;
    void* f();
};

void* S_func_0067e3d0::f()
{
    void* p = m_ptr;
    if (p)
        return (char*)p - 8;
    return 0;
}
