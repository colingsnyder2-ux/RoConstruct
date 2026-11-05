// from server: 100% by atomic.potato
struct SpecialShape {
    char pad[1040];
    double m_410;
    double m_418;
    double m_420;
    double f();
};

double SpecialShape::f()
{
    return m_420 + m_418 + m_410;
}
