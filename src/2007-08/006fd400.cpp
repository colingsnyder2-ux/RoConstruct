// from server: 100% by colin
struct CAutoHidePanelTabManager {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    int m_pad0;
    int m_pad1;
    int m_pad2;
    int m_pad3;
    int m_value;
    void SetTab(int n);
};

void CAutoHidePanelTabManager::SetTab(int n)
{
    if (n > 0)
        n = 0;
    if (n != m_value)
    {
        m_value = n;
        v2();
    }
}
