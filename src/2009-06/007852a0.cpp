// from server: 100% by tester
struct CXTPStatusBar {
    void construct();
    char pad[0x28];
};

extern "C" void (__stdcall *sub_77D558)();
extern "C" void (__stdcall *sub_77EE14)(void*);

void CXTPStatusBar::construct() {
    sub_77D558();
    void (__stdcall *fn)(void*) = sub_77EE14;
    *(int*)((char*)this + 8) = 0;
    *(int*)((char*)this + 0x20) = 0;
    *(int*)((char*)this + 0x1c) = 0;
    *(int*)((char*)this + 0x24) = -1;
    fn((char*)this + 0xc);
    fn((char*)this + 0x28);
}
