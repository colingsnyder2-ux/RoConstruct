// from server: 100% by colin
struct CXTPStatusBar {
    int GetItem(int nIndex);
    char pad[0x98];
    int* m_pItems;
    int m_nCount;
};

int CXTPStatusBar::GetItem(int nIndex) {
    if (nIndex < 0 || nIndex >= m_nCount)
        return 0;
    return m_pItems[nIndex];
}
