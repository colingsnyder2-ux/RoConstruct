// from server: 100% by tester
struct CXTPCommandBar {
    int m_n0;
    int m_n4;
    int m_n8;
    int m_nC;
    CXTPCommandBar* Init();
};

CXTPCommandBar* CXTPCommandBar::Init()
{
    m_n0 = 0;
    m_n8 = 0;
    m_n4 = 0;
    m_nC = 1;
    return this;
}
