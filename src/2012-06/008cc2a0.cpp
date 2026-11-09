// from server: 90% by atomic.potato
struct S_FlagStand_008cc2a0 {
    char pad0[348];
    int m_x;
    int m_y;
    int m_z;
    void f(int *out);
};

void S_FlagStand_008cc2a0::f(int *out)
{
    out[0] = m_x;
    out[1] = m_y;
    out[2] = m_z;
}
