// from server: 100% by tajop
struct CREATESTRUCTA_ {
    void* lpCreateParams;
    void* hInstance;
    void* hMenu;
    void* hwndParent;
    int cy;
    int cx;
    int y;
    int x;
    long style;
    const char* lpszName;
    const char* lpszClass;
    unsigned long dwExStyle;
};

struct CWnd {
    int PreCreateWindow(CREATESTRUCTA_& cs);
};

struct CChatPrompt : CWnd {
    int PreCreateWindow(CREATESTRUCTA_& cs);
};

int CChatPrompt::PreCreateWindow(CREATESTRUCTA_& cs)
{
    if (!CWnd::PreCreateWindow(cs))
        return 0;
    cs.style &= ~0x00300080;
    cs.style |= 0x08000000;
    return 1;
}
