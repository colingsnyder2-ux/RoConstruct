// from server: 100% by tester
struct Geometry {
    char pad[0x20];
    int m_value;
    void SetValue(int value);
};

void Geometry::SetValue(int value)
{
    if (value != m_value)
        m_value = value;
}
