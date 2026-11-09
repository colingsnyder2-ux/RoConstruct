// from server: 66% by atomic.potato
extern "C" void __cdecl sub_008011f0(int, int);

struct S_func_007fee00 {
    int m_value;
    S_func_007fee00* f(int);
};

S_func_007fee00* S_func_007fee00::f(int value)
{
    m_value = value;
    sub_008011f0(value, 1);
    return this;
}
