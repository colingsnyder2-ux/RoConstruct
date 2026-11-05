// from server: 66% by atomic.potato
struct S_func_00639100 {
    char pad0[196];
    char m_value[8];
    char *f();
};

char *S_func_00639100::f()
{
    if (m_value[4] != 0 && m_value[6] == 0)
        return (char *)0x00ccca5c;
    return 0;
}
