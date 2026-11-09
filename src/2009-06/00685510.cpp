// from server: 100% by why2
struct S_func_00685510 {
    char pad0[0x58];
    unsigned int m_x;
    int f();
};

int S_func_00685510::f()
{
    return (m_x >> 2) & 1;
}
