// from server: 100% by colin
struct CXTPCommandBar {
    char pad[0xc8];
    int m_nMinWidth;
    int m_nMinHeight;
    char pad2[0xe4 - 0xcc - 4];
    unsigned int m_dwFlags;
    void Reset();
};

void CXTPCommandBar::Reset()
{
    m_dwFlags |= 1;
    m_nMinWidth = -1;
    m_nMinHeight = -1;
}
