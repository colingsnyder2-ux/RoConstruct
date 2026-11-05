// from server: 48% by atomic.potato
struct S_func_008c1330 {
    char pad0[84];
    unsigned char m_enabled;
    char pad1[87];
    int m_callback;
    int f();
};

int S_func_008c1330::f()
{
    if (!m_enabled)
        return 0;
    ((void (__thiscall *)(S_func_008c1330 *, void *, int))(*(int *)((char *)this - 172 + 0x5c)))(
        (S_func_008c1330 *)((char *)this - 172),
        (void *)((char *)this + 36), 0);
    return 0;
}
