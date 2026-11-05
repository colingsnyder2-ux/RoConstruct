// from server: 100% by king_originala
struct Rect
{
    int left, top, right, bottom;
    Rect(int l, int t, int r, int b);
};

__forceinline Rect::Rect(int l, int t, int r, int b)
    : left(l), top(t), right(r), bottom(b)
{
}

struct Pane;

struct CMainFrame
{
    Pane* FindPane(unsigned int id, Rect bounds, int flags);
    void f();
};

void CMainFrame::f()
{
    FindPane(191, Rect(0, 0, 280, 400), 0);
}
