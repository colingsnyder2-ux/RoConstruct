// from server: 100% by why2
// roc 2009-06 00819180  unit: CXTMemDC  size: 16 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00819180
//
// 00819180  8bc1                 mov eax, ecx
// 00819182  8b4804               mov ecx, dword ptr [eax + 4]
// 00819185  8b11                 mov edx, dword ptr [ecx]
// 00819187  8b00                 mov eax, dword ptr [eax]
// 00819189  8b5238               mov edx, dword ptr [edx + 0x38]
// 0081918c  50                   push eax
// 0081918d  ffd2                 call edx
// 0081918f  c3                   ret

struct CXTMemDC {
    int m_nSavedDC;
    struct Inner* m_pInner;
    void Restore();
};

struct Inner {
    virtual void vfunc0();
    virtual void vfunc1();
    virtual void vfunc2();
    virtual void vfunc3();
    virtual void vfunc4();
    virtual void vfunc5();
    virtual void vfunc6();
    virtual void vfunc7();
    virtual void vfunc8();
    virtual void vfunc9();
    virtual void vfunc10();
    virtual void vfunc11();
    virtual void vfunc12();
    virtual void vfunc13();
    virtual void Restore(int nSavedDC);
};

void CXTMemDC::Restore() {
    m_pInner->Restore(m_nSavedDC);
}
