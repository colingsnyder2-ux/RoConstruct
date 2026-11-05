// from server: 100% by tester
extern "C" int (__stdcall *IsWindow)(void*);

struct CXTColorSelectorCtrl {
    char pad[0x160];
    void* m_hwnd;
    int IsVisible();
};

int CXTColorSelectorCtrl::IsVisible()
{
    if (m_hwnd != 0) {
        if (IsWindow(*(void**)((char*)m_hwnd + 0x20)) != 0)
            return 1;
    }
    return 0;
}
