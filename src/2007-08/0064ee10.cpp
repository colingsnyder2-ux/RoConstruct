// from server: 44% by colin
struct CXTPToolBar {
    void method_64EE10();
};

extern "C" void __stdcall sub_647330();
extern "C" void __stdcall sub_64EE90();

void CXTPToolBar::method_64EE10() {
    *(void**)this = (void*)0x7c7384;
    *(void**)((char*)this + 0x54) = (void*)0x7c7374;
    *(void**)((char*)this + 0x5c) = (void*)0x7c7314;
    void* p = *(void**)((char*)this + 0x184);
    if (p) {
        void** vtbl = *(void***)p;
        void (__thiscall *fn)(void*, int) = (void (__thiscall *)(void*, int))vtbl[0];
        fn(p, 1);
        *(void**)((char*)this + 0x184) = 0;
    }
    sub_647330();
}
