// from server: 100% by colin
extern "C" int (__stdcall *IsWindowVisible)(void*);

struct CXTPControlCustom {
    char pad[0x170];
    void* hwnd;
    void SetVisible2(int);

    void SetVisible(int bVisible);
};

void CXTPControlCustom::SetVisible(int bVisible)
{
    if (hwnd != 0 && IsWindowVisible(hwnd) != 0)
        return;
    SetVisible2(bVisible);
}
