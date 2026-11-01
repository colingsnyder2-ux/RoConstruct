// from server: 100% by colin
extern "C" __declspec(dllimport) int __stdcall InvalidateRect(void*, const void*, int);

struct CXTPDockingPaneTabbedContainer {
    char pad[0xf0];
    int field_f0;
    void CheckAndInvalidate(void* p, int bErase);
};

void CXTPDockingPaneTabbedContainer::CheckAndInvalidate(void* p, int bErase) {
    if (field_f0 != 0)
        return;
    char* base = (char*)this - 0xa8;
    if (base == 0)
        return;
    if (*(int*)(base + 0x20) == 0)
        return;
    void* hwnd = *(void**)((char*)this - 0x88);
    InvalidateRect(hwnd, p, 0);
}
