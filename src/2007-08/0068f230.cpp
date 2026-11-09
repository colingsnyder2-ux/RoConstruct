// from server: 100% by colin
extern "C" __declspec(dllimport) int __stdcall ShowWindow(void*, int);

struct Inner {
    void* GetSomething();
};

struct CXTPDockingPane {
    char pad[0x20];
    Inner field_20;
    char pad2[0xb4 - 0x24];
    void* field_b4;
    void Show(int);
};

void CXTPDockingPane::Show(int nCmdShow) {
    if (nCmdShow) {
        Inner* p = &field_20;
        void* obj = p->GetSomething();
        void* vtable = *(void**)obj;
        typedef void (__thiscall *Fn)(void*, int, void*);
        Fn fn = *(Fn*)((char*)vtable + 0x140);
        fn(obj, 1, this);
    }
    void* hwnd = *(void**)((char*)this + 0xb4);
    if (hwnd) {
        int cmd = nCmdShow ? 5 : 0;
        ShowWindow(hwnd, cmd);
    }
}
