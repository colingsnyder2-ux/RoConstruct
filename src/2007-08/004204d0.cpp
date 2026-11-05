// from server: 100% by tajop
extern "C" __declspec(dllimport) long __stdcall SendMessageA(void* hWnd, unsigned int Msg, unsigned int wParam, long lParam);
extern "C" void __stdcall sub_6301C0(void*);
struct CXTTreeBase {
    void OnNotify(int code, int id, int param);
};

struct CRobloxTreeCtrl {
    char pad[0x20];
    void* hWnd;
    char pad2[0x54 - 0x24];
    CXTTreeBase base;
    void OnNotify(int code, int id, int param);
};

void CRobloxTreeCtrl::OnNotify(int code, int id, int param) {
    if (code == 0x71) {
        void* r1 = (void*)SendMessageA(hWnd, 0x110a, 9, 0);
        void* r2 = (void*)SendMessageA(hWnd, 0x110e, 0, (long)r1);
        sub_6301C0(r2);
    }
    base.OnNotify(code, id, param);
}
