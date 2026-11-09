// from server: 66% by colin
struct CXTPRibbonBar {
    int f();
};

extern "C" int __cdecl sub_006a7bd0();

int CXTPRibbonBar::f() {
    if (sub_006a7bd0()) {
        return (*(int (__thiscall **)(CXTPRibbonBar *))(*(int *)this + 0x210))(this);
    }
    return 0;
}
