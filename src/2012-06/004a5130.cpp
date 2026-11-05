// from server: 100% by tajop
extern "C" void* (__stdcall* pLoadCursorA)(void*, const char*);
const char* __stdcall AfxRegisterWndClass(unsigned int, void*, void*, void*);

struct CREATESTRUCTA
{
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

struct Base
{
    int PreCreateWindow(CREATESTRUCTA& cs);
};

struct S : Base
{
    int PreCreateWindow(CREATESTRUCTA& cs);
};

int S::PreCreateWindow(CREATESTRUCTA& cs)
{
    const char* cls = AfxRegisterWndClass(8, pLoadCursorA(0, (const char*)0x7f00), 0, 0);
    cs.style |= 0x6000000;
    cs.lpszClass = cls;
    return Base::PreCreateWindow(cs);
}
