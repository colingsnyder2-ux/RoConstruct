// from server: 100% by colin
struct CXTPMenuBar {
    void sub_6A6100();
    virtual int vfunc_160();
    void sub_6A67A0();
    void func_6A6BD0();
};

void CXTPMenuBar::func_6A6BD0()
{
    sub_6A6100();
    if (((int (__thiscall*)(CXTPMenuBar*))((*(void***)this)[0x160 / 4]))(this))
        sub_6A67A0();
}
