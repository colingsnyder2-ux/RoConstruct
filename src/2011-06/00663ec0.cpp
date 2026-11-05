// from server: 100% by atomic.potato
struct S_func_00663ec0 {
    char pad0[2];
    unsigned char m_flag2;
    char pad3[3];
    unsigned char m_flag6;
    int f();
};

int S_func_00663ec0::f()
{
    return m_flag2 != 0 || m_flag6 != 0;
}
