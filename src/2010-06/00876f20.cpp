// from server: 100% by tester
struct CXTPGraphicBitmapPng {
    char pad[0x20];
    void* m_hWnd;
    char pad2[0x40];
    int m_nID;
    void Refresh();
};

extern "C" int (__stdcall *InvalidateRect)(void*, const void*, int);
extern "C" void __fastcall sub_6F2430(int);

void CXTPGraphicBitmapPng::Refresh()
{
    InvalidateRect(m_hWnd, 0, 0);
    sub_6F2430(m_nID);
}
