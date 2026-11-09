// from server: 100% by colin
struct CXTPRibbonBarCControlCaptionButton {
    void OnClick();
};

extern "C" void* __fastcall sub_646570(void* p);

extern "C" int (__stdcall *PostMessageA)(void* hWnd, unsigned int Msg, unsigned int wParam, int lParam);

void CXTPRibbonBarCControlCaptionButton::OnClick() {
    void* p = *(void**)((char*)this + 0x84);
    void* q = *(void**)((char*)this + 0xfc);
    void* r = sub_646570(q);
    unsigned int w = *(unsigned int*)((char*)r + 0x20);
    PostMessageA((void*)w, 0x112, (unsigned int)p, 0);
}
