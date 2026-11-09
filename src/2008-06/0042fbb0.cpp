// from server: 100% by king_originala
struct Rect {
    int left, top, right, bottom;

    Rect(int l, int t, int r, int b)
        : left(l), top(t), right(r), bottom(b) {}
};

struct CMainFrame {
    void f();
    void set(unsigned int, Rect, int);
};

void CMainFrame::f()
{
    set(0xc0, Rect(0, 0, 0x280, 0xc8), 3);
}
