// from server: 100% by colin
extern "C" __declspec(dllimport) int __stdcall IsRectEmpty(const void*);
extern "C" __declspec(dllimport) int __stdcall SetRectEmpty(void*);

struct CXTPCommandBar {
    void* field0;
    char pad[0x134];
    char field138[16];
    void f();
};

void CXTPCommandBar::f() {
    if (IsRectEmpty(field138) == 0) {
        SetRectEmpty(field138);
        void** vtable = *(void***)this;
        void (__thiscall *fn)(CXTPCommandBar*, int, int) = (void (__thiscall *)(CXTPCommandBar*, int, int))vtable[0x19c / 4];
        fn(this, 0, 1);
    }
}
