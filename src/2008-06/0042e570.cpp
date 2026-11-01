// from server: 100% by king_originala
struct Rect
{
    int left, top, right, bottom;
};

struct Pane;

struct PaneVTable
{
    void* slots[22];
    int (__thiscall* invoke)(Pane*);
};

struct Pane
{
    PaneVTable* vtable;
};

struct PaneManager
{
    Pane* FindPane(int id);
    Pane* CreatePane(int id, Rect rect, int direction, Pane* relative);
    void ShowPane(Pane* pane, int focus);
};

struct CMainFrame
{
    char padding[0x138];
    PaneManager manager;

    int func_0042e570(int id, Rect rect, int direction);
};

int CMainFrame::func_0042e570(int id, Rect rect, int direction)
{
    Pane* pane = manager.FindPane(id);
    if (!pane)
        pane = manager.CreatePane(id, rect, direction, 0);

    manager.ShowPane(pane, 1);
    return pane->vtable->invoke(pane);
}
