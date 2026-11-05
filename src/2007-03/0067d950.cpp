// from server: 100% by tester
struct CXTPStatusBar
{
    int IsCustom();
    char pad[0x30];
    unsigned int m_nStyle;
};

int CXTPStatusBar::IsCustom()
{
    return m_nStyle >= 0x50050 ? 1 : 0;
}
