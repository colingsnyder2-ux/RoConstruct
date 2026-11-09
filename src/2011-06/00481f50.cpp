// from server: 29% by atomic.potato
extern "C" void* __cdecl sub_0080A05E(unsigned int size);

struct CRobloxReportPaneView
{
    void init();
    void* construct();
};

void CRobloxReportPaneView::init()
{
}

void* CRobloxReportPaneView::construct()
{
    void* p = sub_0080A05E(0x3bc);
    if (p != 0)
    {
        ((CRobloxReportPaneView*)p)->init();
        *(void**)p = (void*)0xa71f2c;
    }
    return p;
}
