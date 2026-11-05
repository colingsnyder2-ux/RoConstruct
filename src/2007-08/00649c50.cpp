// from server: 100% by colin
struct CXTPCommandBar {
    char pad0[0x30];
    char field30[0x10];
    char field40[0x10];
    char field50[0x10];
    char field60[0x10];
    char field70[0x10];
    char field80[0x10];
    char field90[0x10];
    char fieldA0[0x10];

    void sub_6486b0(int);
    void sub_6496a0();
    void sub_63069a();
    void func_649c50();
};

void CXTPCommandBar::func_649c50() {
    *(int*)this = 0x7c6bfc;
    sub_6486b0(1);
    ((CXTPCommandBar*)((char*)this + 0xa0))->sub_6496a0();
    ((CXTPCommandBar*)((char*)this + 0x90))->sub_6496a0();
    ((CXTPCommandBar*)((char*)this + 0x80))->sub_6496a0();
    ((CXTPCommandBar*)((char*)this + 0x70))->sub_6496a0();
    ((CXTPCommandBar*)((char*)this + 0x60))->sub_6496a0();
    ((CXTPCommandBar*)((char*)this + 0x50))->sub_6496a0();
    ((CXTPCommandBar*)((char*)this + 0x40))->sub_6496a0();
    ((CXTPCommandBar*)((char*)this + 0x30))->sub_6496a0();
    sub_63069a();
}
