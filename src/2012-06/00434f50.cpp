// from server: 58% by Intel





struct CXTPDockingPaneManager;

struct CMainFrame
{
    CXTPDockingPaneManager* m_pDockingPaneManager;
    void f(int a1, int a2, int a3, int a4, int a5, int a6);
};

struct CXTPDockingPaneBase
{
    virtual void Release() = 0;
};

struct CXTPDockingPaneManager
{
    CXTPDockingPaneBase* FindPane(int id);
    CXTPDockingPaneBase* CreatePane(int id, int a2, int a3, int a4, int a5, int a6);
    void AddPane(CXTPDockingPaneBase* pane, int flag);
};

void CMainFrame::f(int a1, int a2, int a3, int a4, int a5, int a6)
{
    CXTPDockingPaneManager* manager = m_pDockingPaneManager;
    CXTPDockingPaneBase* pane = manager->FindPane(a1);
    if (!pane)
    {
        pane = manager->CreatePane(a1, a2, a3, a4, a5, a6);
    }
    manager->AddPane(pane, 1);
    pane->Release();
}
