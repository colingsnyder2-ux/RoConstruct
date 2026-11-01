// from server: 100% by king_originala
extern "C" void* (__stdcall *LoadCursorA)(void*, const char*);
extern const char* __stdcall RegisterWindowClass(unsigned int, void*, void*, void*);

struct CreateStruct {
    void* createParams;
    void* instance;
    void* menu;
    void* parent;
    int cy;
    int cx;
    int y;
    int x;
    long style;
    const char* name;
    const char* className;
    unsigned long extendedStyle;
};

template<class T>
inline const T& maximum(const T& a, const T& b)
{
    return a < b ? b : a;
}

struct WindowBase {
    int PreCreateWindow(CreateStruct*);
};

struct CRobloxWnd : WindowBase {
    int PreCreateWindow(CreateStruct*);
};

int CRobloxWnd::PreCreateWindow(CreateStruct* cs)
{
    cs->className = RegisterWindowClass(
        0x2b, LoadCursorA(0, (const char*)0x7f00), 0, 0);
    cs->style |= 0x06000000;
    cs->cx = maximum(cs->cx, 100);
    cs->cy = maximum(cs->cy, 100);
    return WindowBase::PreCreateWindow(cs);
}
