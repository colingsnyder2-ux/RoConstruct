// from server: 100% by king_originala
struct POINT {
    long x, y;
};

struct RECT {
    long left, top, right, bottom;
};

extern "C" {
    extern int (__stdcall *GetClientRect)(void*, RECT*);
    extern int (__stdcall *ClientToScreen)(void*, POINT*);
}

struct Window {
    char padding[0x20];
    void* handle;
};

struct CSettingsDialog {
    char padding[0x16c];
    Window* window;
    bool f();
};

bool CSettingsDialog::f()
{
    RECT rect;
    GetClientRect(window->handle, &rect);

    POINT point;
    point.x = rect.left;
    point.y = rect.top;

    long x = point.x;
    long y = point.y;
    ClientToScreen(window->handle, &point);

    if (point.x != x || point.y != y)
        return false;
    return true;
}
