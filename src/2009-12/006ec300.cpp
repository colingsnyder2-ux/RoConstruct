// from server: 45% by atomic.potato
struct Geometry_006ec300 {
    char pad0[144];
    int m_value;
    int f();
};

int Geometry_006ec300::f()
{
    if (m_value == 0)
        return 1;
    if (m_value == 1)
        return 5;
    if (m_value == 2)
        return 20;
    return 1;
}
