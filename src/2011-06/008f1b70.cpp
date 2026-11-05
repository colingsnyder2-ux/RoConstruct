// from server: 44% by atomic.potato




struct CXTPButton {
    char pad0[0xac];
    void* field_ac;
};

struct CXTPResource {
    char pad0[0x81];
    char field_81;
    char pad1[0x4e];
    char field_d0[0x10];
};

extern "C" {
    int __stdcall IsWindow(void* hWnd);
    void __stdcall OffsetRect(void* lprc, int dx, int dy);
}

extern "C" void __cdecl sub_85d120(void* dest, void* src, void* rect);
extern "C" void __cdecl sub_85d1a0(void* p);
extern "C" void __cdecl sub_8100f0(void* pRect, void* pButton, int n);

struct CXTCaptionButtonTheme {
    void RefreshMetrics(void* pButton, int nState, int nStyle, int nFlags);
};

void CXTCaptionButtonTheme::RefreshMetrics(void* pButton, int nState, int nStyle, int nFlags)
{
    CXTPButton* pBtn = (CXTPButton*)pButton;
    CXTPResource* pRes = (CXTPResource*)pBtn->field_ac;
    void* hWnd;
    if (pRes == 0)
        hWnd = 0;
    else
        hWnd = *(void**)((char*)pRes + 0x20);
    if (!IsWindow(hWnd))
        return;
    if (pRes->field_81 == 0)
        return;
    if (*(char*)pRes->field_d0 != 0)
        return;
    void* pTheme = *(void**)this;
    void* pfn = *(void**)((char*)pTheme + 0x20);
    void* result = ((void* (__thiscall*)(void*, void*))pfn)(this, pButton);
    void* local;
    void* pRect = &local;
    sub_85d120(&local, result, pRect);
    void* pTheme2 = *(void**)this;
    void* pfn2 = *(void**)((char*)pTheme2 + 0x48);
    void* vtable = *(void**)pRect;
    void* result2 = ((void* (__thiscall*)(void*, void*, void*))pfn2)(this, pButton, pRect);
    void* pfn3 = *(void**)((char*)vtable + 0x38);
    ((void (__thiscall*)(void*, void*))pfn3)(pRect, result2);
    if ((nState & 1) && *(void**)((char*)this + 0x18) != 0)
        OffsetRect(pRect, 1, 1);
    sub_8100f0(pRect, pButton, 0x8825);
    sub_85d1a0(&local);
}
