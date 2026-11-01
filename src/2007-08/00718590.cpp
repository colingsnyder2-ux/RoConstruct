// from server: 100% by colin
struct CXTPRibbonControlTab {
    char m_pad[0x1b4];
    int m_value;
    int GetValue(int* pOut);
};

int CXTPRibbonControlTab::GetValue(int* pOut) {
    if (pOut == 0)
        return 0x80070057;
    *pOut = m_value;
    return 0;
}
