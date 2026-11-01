// from server: 100% by colin
struct CXTPRibbonBar
{
    char pad[0x27c];
    int m_nField;
    bool IsSet();
};

bool CXTPRibbonBar::IsSet()
{
    return m_nField != 0;
}
