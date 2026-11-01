// from server: 100% by tester
struct CXTPCommandBar
{
    int m_field0;
    int m_field4;
    int m_field8;
    int m_fieldC;
    CXTPCommandBar* construct(int value);
};

CXTPCommandBar* CXTPCommandBar::construct(int value)
{
    m_field0 = value;
    m_field8 = 0;
    m_field4 = 0;
    m_fieldC = 0;
    return this;
}
