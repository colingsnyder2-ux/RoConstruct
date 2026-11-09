// from server: 100% by tester
struct CXTPControl {
    char pad[0xc0];
    int field_c0;
    char pad2[0xfc - 0xc4];
    void* field_fc;
    void GetRect();
};

extern "C" {
    __declspec(dllimport) int __stdcall GetCursorPos(void*);
    __declspec(dllimport) int __stdcall PtInRect(const void*, int, int);
    __declspec(dllimport) int __stdcall ScreenToClient(void*, void*);
}

void CXTPControl::GetRect()
{
    int pt[2];
    GetCursorPos(pt);
    void* p = field_fc;
    void* r = *(void**)((char*)p + 0x20);
    ScreenToClient(r, pt);
    PtInRect((char*)this + 0xc0, pt[0], pt[1]);
}
