// from server: 100% by Gemini
extern "C" {
    extern void* (__stdcall *GetParent)(void*);
    extern int (__stdcall *InvalidateRgn)(void*, void*, int);
}

extern unsigned char toggled;

struct View {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual int width();
    virtual int height();
};

struct Holder {
    unsigned char reserved[12];
    View* view;
};

struct S {
    unsigned char reserved0[0x20];
    void* window;
    unsigned char reserved1[0x94];
    Holder* holder;

    void update(int);
    bool f();
};

S* __stdcall fromHandle(void*);

struct Bounds {
    unsigned char reserved0[0x1c];
    int left;
    int top;
    int right;
    int bottom;
    unsigned char reserved1[0x28];

    Bounds(S*);
    ~Bounds();
};

struct Rect {
    int left;
    int top;
    int right;
    int bottom;
    Rect(int l, int t, int r, int b) : left(l), top(t), right(r), bottom(b) {}
};

bool S::f()
{
    if (!toggled) {
        bool tooSmall = false;
        {
            Bounds bounds(this);
            Rect rect(bounds.left, bounds.top, bounds.right, bounds.bottom);

            if (rect.right || rect.left || rect.top || rect.bottom) {
                if (rect.right - rect.left + 1 < holder->view->width() ||
                    rect.bottom - rect.top + 1 < holder->view->height()) {
                    holder->view->width();
                    holder->view->height();
                    tooSmall = true;
                }
            }
        }

        if (tooSmall) {
            void* (__stdcall *parent)(void*) = GetParent;
            S* wnd = this;
            while (fromHandle(parent(wnd->window))) {
                wnd = fromHandle(parent(wnd->window));
            }
            InvalidateRgn(wnd->window, 0, 0);
            toggled = 1;
            return false;
        }
    } else {
        toggled = 0;
    }

    update(1);
    return true;
}
