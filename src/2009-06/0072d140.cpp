// from server: 100% by why2
struct CXTPCommandBarCmdUI {
    int field_0x28;
    void sub_720020(int);
    void func(int);
};

void CXTPCommandBarCmdUI::func(int arg) {
    CXTPCommandBarCmdUI* p = *(CXTPCommandBarCmdUI**)((char*)this + 0x28);
    if (p != 0) {
        p->sub_720020(arg);
    }
}
