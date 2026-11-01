// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD

struct CRect
{
    int left, top, right, bottom;
    CRect(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
};

class CXTPCmdTarget { char pad[0x1c]; public: virtual ~CXTPCmdTarget(); };
class CXTPDockingPaneBase { public: virtual ~CXTPDockingPaneBase(); };
class CXTPDockingPane : public CXTPCmdTarget, public CXTPDockingPaneBase {};

class CXTPDockingPaneManager
{
public:
    CXTPDockingPane* FindPane(int nID) const;
    void AttachPane(CXTPDockingPaneBase* pPane, CXTPDockingPaneBase* pNeighbour);
};

class CMainFrame
{
    char padding[0x13c];
    CXTPDockingPaneManager m_paneManager;
public:
    int ShowPane(int id, CRect rect, int direction);
    void OnViewPaneA();
};

void CMainFrame::OnViewPaneA()
{
    bool created = m_paneManager.FindPane(0x8c) == 0;
    ShowPane(0x8c, CRect(0, 0, 0x14a, 0x190), 0);
    if (created)
    {
        CXTPDockingPane* neighbour = m_paneManager.FindPane(0xda);
        if (neighbour)
            m_paneManager.AttachPane(m_paneManager.FindPane(0x8c), neighbour);
    }
}
