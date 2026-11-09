// from server: 100% by tester
struct CXTPCommandBar {
    char pad[0xf0];
    unsigned int m_dwStyle;
    void SetFlag(int bSet);
};

void CXTPCommandBar::SetFlag(int bSet)
{
    if (bSet != 0)
        m_dwStyle |= 0x400000;
    else
        m_dwStyle &= 0xffbfffff;
}
