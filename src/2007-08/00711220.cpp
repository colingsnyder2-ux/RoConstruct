// from server: 100% by colin
struct CXTColorSelectorCtrl {
    char pad[0x20];
    void* hwnd;
    char pad2[0x54];
    int field78;
    int field7c;
    bool sub_710fd0();
    void sub_63023e();
    void OnLButtonDown(unsigned int nFlags, int x, int y);
};

extern "C" {
    int (__stdcall *GetClientRect)(void* hwnd, void* rect);
    int (__stdcall *PtInRect)(const void* rect, int x, int y);
    int (__stdcall *InvalidateRect)(void* hwnd, const void* rect, int erase);
}

void CXTColorSelectorCtrl::OnLButtonDown(unsigned int nFlags, int x, int y)
{
    if (sub_710fd0())
        return;

    sub_63023e();

    int rect[4];
    GetClientRect(hwnd, rect);

    if (!PtInRect(rect, x, y))
        return;

    field7c = field78;
    InvalidateRect(hwnd, 0, 0);
}
