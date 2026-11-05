// from server: 100% by king_originala
struct Rect
{
    int left, top, right, bottom;
};

struct Pane;

struct CWrapperView
{
    Pane* FindPane(int, Rect, int);
    Pane* method();
};

Pane* CWrapperView::method()
{
    Rect rect = { 0, 0, 150, 400 };
    return FindPane(140, rect, 0);
}
