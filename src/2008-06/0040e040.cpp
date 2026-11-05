// from server: 100% by king_originala
struct Control;

struct Size {
    int cx;
    int cy;
};

struct ControlTable {
    void* slots[129];
    Size* (__thiscall* measure)(Control*, Size*, int, int, int);
};

struct Control {
    ControlTable* table;
    char padding[28];
    void* window;
    char remainder[92];

    void __thiscall move(int, int, int, int, int);
    void __thiscall position(void*, int, int, int, int, unsigned int);
};

extern "C" {
    extern int (__stdcall* InvalidateRect)(void*, const void*, int);
}

struct CBrowserView {
    char padding[156];
    Control lower;
    Control upper;

    void resize(int, int, int);
};

void CBrowserView::resize(int unused, int width, int height) {
    int topHeight = 0;
    Control* top = &upper;

    if (top && top->window) {
        Size temporary;
        Size size = *top->table->measure(top, &temporary, width, 203, 0);
        topHeight = size.cy;
        top->move(0, 0, width, topHeight, 1);
        InvalidateRect(upper.window, 0, 0);
    }

    Control* bottom = &lower;
    if (bottom && bottom->window)
        bottom->position(0, 0, topHeight, width, height - topHeight, 28);
}
