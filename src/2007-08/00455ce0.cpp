// from server: 41% by colin
struct CRobloxReportPaneView {
    void* construct();
};

extern "C" void* __cdecl operator_new(unsigned int size);
extern "C" void __cdecl CRobloxReportPaneView_base_ctor(void* p);

void* CRobloxReportPaneView::construct()
{
    CRobloxReportPaneView* p = (CRobloxReportPaneView*)operator_new(0x318);
    if (p != 0) {
        CRobloxReportPaneView_base_ctor(p);
        *(void**)p = (void*)0x7926c4;
        *(void**)((char*)p + 0x2cc) = (void*)0x7926b0;
        *(void**)((char*)p + 0x2e8) = (void*)0x79269c;
    }
    return p;
}
