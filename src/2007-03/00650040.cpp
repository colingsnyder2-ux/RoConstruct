// from server: 100% by tester
struct CXTPRibbonControlTab {
    char pad0[0x73aace];
    char pad1[0x20];
    int f();
};

extern "C" void __fastcall sub_73833a(void*);
extern "C" void __fastcall sub_716ed0(void*);

int CXTPRibbonControlTab::f() {
    sub_73833a(this);
    *(int*)this = 0x7c66f4;
    sub_716ed0((char*)this + 0x20);
    *(int*)((char*)this + 0x34) = 0;
    *(int*)((char*)this + 0x38) = 0;
    return (int)this;
}