// from server: 92% by tajop
struct CXTPToolBar
{
    char pad[0xe8];
    unsigned int m_dwFlags;
};

struct CXTPDockBarArray
{
    void* vtbl;
    void** m_pData;
    int m_nSize;
    int m_nMaxSize;
    int m_nGrowBy;
    void InsertAt(int nIndex, void* newElement, int nCount);
};

struct CXTPDockBar
{
    char pad[0x58];
    CXTPDockBarArray m_arrBars;
    CXTPToolBar* GetDockedCommandBar(int nPos);
    void AdjustStretchBars();
};

void CXTPDockBar::AdjustStretchBars()
{
    for (int i = 0; i < m_arrBars.m_nSize; i++)
    {
        CXTPToolBar* pBar = GetDockedCommandBar(i);
        if (pBar && (pBar->m_dwFlags & 0x40))
        {
            if (i > 0 && GetDockedCommandBar(i - 1))
            {
                m_arrBars.InsertAt(i, 0, 1);
                i++;
            }
            if (i < m_arrBars.m_nSize - 1 && GetDockedCommandBar(i + 1))
            {
                m_arrBars.InsertAt(i + 1, 0, 1);
                i++;
            }
        }
    }
}
