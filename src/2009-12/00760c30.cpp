// from server: 50% by atomic.potato
extern "C" void __cdecl sub_007f385a(int);

struct S_func_00760c30 {
    char pad0[160];
    int m_value;
    void SetImpl();
};

void S_func_00760c30::SetImpl()
{
    if (m_value)
        sub_007f385a(m_value);
}
