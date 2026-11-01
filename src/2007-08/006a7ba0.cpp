// from server: 100% by colin
struct CXTPRibbonBar {
    int m_nSomething;
    char pad[0x280];
    int m_nCount;
    int GetFrameHelper();
    int GetRibbonBar();
    int GetHeight();
};

int CXTPRibbonBar::GetHeight()
{
    int result;
    if (m_nCount > 0)
        return m_nCount;
    int a = GetFrameHelper();
    int b = *(int*)(a + 0xfc);
    int c = GetRibbonBar();
    int d = *(int*)(c + 0x640);
    result = d + b * 3 + 0xa;
    return result;
}
