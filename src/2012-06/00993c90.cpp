// roc 2012-06 00993c90  unit: CXTPCommandBar  size: 27 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00993c90
//
// 00993c90  56                   push esi
// 00993c91  8bf1                 mov esi, ecx
// 00993c93  e818f1ffff           call 0x992db0
// 00993c98  8b4c2408             mov ecx, dword ptr [esp + 8]
// 00993c9c  8b10                 mov edx, dword ptr [eax]
// 00993c9e  8b5274               mov edx, dword ptr [edx + 0x74]
// 00993ca1  56                   push esi
// 00993ca2  51                   push ecx
// 00993ca3  8bc8                 mov ecx, eax
// 00993ca5  ffd2                 call edx
// 00993ca7  5e                   pop esi
// 00993ca8  c20400               ret 4
// copied from an identical function in another client (function ?Method@CXTPCommandBar@ns_ROCX00000f@@QAEXH@Z)

namespace ns_ROCX00000f {
struct CXTPCommandBar;

struct CXTPCommandBar_Inner {
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual void vfunc_0c();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1c();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2c();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3c();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4c();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5c();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6c();
    virtual void vfunc_70();
    virtual void vfunc_74(int, CXTPCommandBar*);
};

struct CXTPCommandBar {
    CXTPCommandBar_Inner* GetInner();
    void Method(int arg);
};

void CXTPCommandBar::Method(int arg) {
    CXTPCommandBar_Inner* inner = GetInner();
    inner->vfunc_74(arg, this);
}
}
