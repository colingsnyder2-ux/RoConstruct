// from server: 100% by king_originala
struct Rect
{
    int left, top, right, bottom;
    Rect(int l, int t, int r, int b)
        : left(l), top(t), right(r), bottom(b) {}
};

struct PaneBase
{
    int value;
};

struct Pane
{
    char padding[0x20];
    PaneBase base;
};

struct PaneManager
{
    Pane* FindPane(int id);
    void DockPane(PaneBase* pane, int direction, PaneBase* relative);
};

struct CMainFrame
{
    char padding[0x138];
    PaneManager manager;

    Pane* FindPane(int id, Rect rect, bool show);
    void f();
};

void CMainFrame::f()
{
    bool missing = manager.FindPane(0xc1) == 0;
    FindPane(0xc1, Rect(0, 0, 250, 300), true);

    if (missing)
    {
        Pane* relative = manager.FindPane(0xc2);
        if (relative)
        {
            PaneBase* base = &relative->base;
            Pane* pane = manager.FindPane(0xc1);
            manager.DockPane(pane ? &pane->base : 0, 3, base);
        }
    }
}
