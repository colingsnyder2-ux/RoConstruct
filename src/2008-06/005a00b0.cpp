// from server: 100% by tester
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD /fp:fast
struct SpecialShape
{
    char pad[448];
    float m_1c0;
    char pad2[12];
    double m_1d0;
    double f();
};

double g_817a88 = 100.0;

double SpecialShape::f()
{
    return (1.0 / m_1c0) * m_1d0 * g_817a88;
}
