// from server: 100% by colin
struct CXTPDockingPane
{
    char pad[0x30];
    struct CXTPDockingPane *m_pPane;
    int IsActivePane();
};

int CXTPDockingPane::IsActivePane()
{
    CXTPDockingPane *p = m_pPane;
    if (p == 0)
        return 0;
    return *(CXTPDockingPane **)((char *)p + 0x14c) == this;
}
