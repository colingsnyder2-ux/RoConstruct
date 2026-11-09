// from server: 100% by tajop
struct CXTPPropertyGridItemColor {
    char pad0[0x80];
    void* m_pOwner;
    char pad1[0xb8 - 0x84];
    unsigned int m_hWnd;
    char pad2[0x17c - 0xbc];
    unsigned int m_nID;
    void OnInplaceButtonDown();
};

extern "C" __declspec(dllimport) void __stdcall SendMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);
extern "C" void __fastcall sub_63094c(void* p);

void CXTPPropertyGridItemColor::OnInplaceButtonDown()
{
    sub_63094c(this);
    void* p = *(void**)((char*)this + 0x80);
    SendMessageA(*(void**)((char*)p + 0x20), 0x272b, *(unsigned int*)((char*)this + 0xb8), *(long*)((char*)this + 0x17c));
}
