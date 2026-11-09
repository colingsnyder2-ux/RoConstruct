// from server: 100% by tester
struct CXTPStatusBar {
    char pad[0x3c];
    unsigned int m_dwStyle;
    char pad2[0x5c - 0x40];
    void* m_pFrameHelper;
    void SetStyle(unsigned int dwRemove, unsigned int dwAdd);
};

void CXTPStatusBar::SetStyle(unsigned int dwRemove, unsigned int dwAdd)
{
    unsigned int dwStyle = m_dwStyle;
    unsigned int dwNewStyle = (dwStyle | dwAdd) & ~dwRemove;
    if (dwStyle != dwNewStyle)
    {
        m_dwStyle = dwNewStyle;
        if (m_pFrameHelper != 0)
        {
            (*(void (__thiscall **)(void*))(*(unsigned int*)m_pFrameHelper + 0x68))(m_pFrameHelper);
            if (m_pFrameHelper != 0)
            {
                (*(void (__thiscall **)(void*, int))(*(unsigned int*)m_pFrameHelper + 4))(m_pFrameHelper, 1);
            }
            m_pFrameHelper = 0;
        }
    }
}
