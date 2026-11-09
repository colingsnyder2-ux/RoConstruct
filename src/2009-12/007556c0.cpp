// from server: 100% by atomic.potato
struct S_func_007556c0
{
    char pad0[892];
    int m_value;
    int f();
};

extern "C" void __cdecl sub_007555b0();

int S_func_007556c0::f()
{
    sub_007555b0();
    return m_value;
}
