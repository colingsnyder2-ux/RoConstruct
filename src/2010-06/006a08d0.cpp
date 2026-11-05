// from server: 100% by tester
struct S_func_00613350 {
    char pad0[0x58];
    unsigned int m_field54;
    int f();
};

int S_func_00613350::f()
{
    return (m_field54 >> 2) & 1;
}