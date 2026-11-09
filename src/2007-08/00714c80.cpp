// from server: 100% by colin
struct CXTCaptionButton {
    virtual int vfunc_164();
    int method_710f90();
    int method_714c80();
};

extern "C" int __stdcall sub_6978f0();

int CXTCaptionButton::method_714c80() {
    if (((int (__thiscall **)(CXTCaptionButton *))(*(int *)this))[0x164 / 4](this) != 0) {
        int result = this->method_710f90();
        return (*(int (__thiscall **)(int))(*(int *)result + 0x30))(result);
    }
    return *(int *)(sub_6978f0() + 4);
}
