// from server: 100% by colin
struct CXTPCommandBar {
    char pad0[0x40];
    char field40[0x10];
    char field50[0x50];
    char fieldA0[0x10];
    void sub_648640();
    void func_648710();
};

void CXTPCommandBar::func_648710() {
    ((CXTPCommandBar*)((char*)this + 0x40))->sub_648640();
    ((CXTPCommandBar*)((char*)this + 0x50))->sub_648640();
    ((CXTPCommandBar*)((char*)this + 0xa0))->sub_648640();
}
