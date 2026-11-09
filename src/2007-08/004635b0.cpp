// from server: 100% by colin
struct S_func_004635b0 {
    char pad0[0x17c];
    int m_field;
    void f(int value, char flag);
};

void S_func_004635b0::f(int value, char flag)
{
    m_field = flag ? value : 0;
}
