// from server: 55% by colin
extern "C" __declspec(dllimport) unsigned long __stdcall GetCurrentThreadId();
extern "C" __declspec(dllimport) int __stdcall GetClientRect(void*, void*);
extern "C" __declspec(dllimport) unsigned int __stdcall SetTimer(void*, unsigned int, unsigned int, void*);

struct CRobloxWnd {
    char pad[0x20];
    void* hwnd;
    char pad2[0x58 - 0x24];
    int field58;
    char pad3[0x90 - 0x5c];
    unsigned long field90;
    int sub_458ec0(int, int);
    int func(int);
};

int CRobloxWnd::sub_458ec0(int a, int b) {
    return 0;
}

int CRobloxWnd::func(int arg) {
    int rect[4];
    this->field90 = GetCurrentThreadId();
    GetClientRect(this->hwnd, rect);
    int w = rect[2] - rect[0];
    int h = rect[3] - rect[1];
    if (this->field58 == 2) {
        this->sub_458ec0(w, h);
    }
    SetTimer(this->hwnd, 0, 0xc8, 0);
    SetTimer(this->hwnd, 1, 0x64, 0);
    return 0;
}
