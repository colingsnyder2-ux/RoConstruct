// from server: 100% by colin
struct CXTCaptionButton {
    char pad[0x20];
    void* hwnd;
    void sub_69F550(int, int, int, int);
    void sub_69F420(int, int, int, int);
};

extern "C" void* __stdcall sub_710F90();
extern "C" int (__stdcall *InvalidateRect)(void*, const void*, int);

void CXTCaptionButton::sub_69F420(int a, int b, int c, int d) {
    if (a == 0x1a || a == 0x15) {
        void* p = sub_710F90();
        void** vt = *(void***)p;
        ((void (__thiscall*)(void*))vt[1])(p);
        InvalidateRect(hwnd, 0, 0);
    }
    sub_69F550(a, b, c, d);
}
