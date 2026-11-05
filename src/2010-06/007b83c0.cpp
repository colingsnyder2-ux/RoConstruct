// from server: 100% by tester
struct CXTPCommandBar {
    char pad[0xcc];
    int m_nMinWidth;
    int m_nMinHeight;
    char pad2[0xe8 - 0xd0 - 4];
    unsigned int m_dwFlags;
    void Reset();
};

void CXTPCommandBar::Reset()
{
    m_dwFlags |= 1;
    m_nMinWidth = -1;
    m_nMinHeight = -1;
}
