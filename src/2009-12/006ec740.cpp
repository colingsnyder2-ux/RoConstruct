// from server: 100% by atomic.potato
struct Geometry {
    char pad0[268];
    int m_data[68];
    void f(int index, int value);
};

void Geometry::f(int index, int value)
{
    if (m_data[index] != value)
        m_data[index] = value;
}
