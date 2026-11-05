// from server: 100% by why2
// roc 2009-06 007c80b0  unit: PAVCXTPReportHyperlink::?$CXTPArrayT  size: 7 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007c80b0
//
// 007c80b0  8b01                 mov eax, dword ptr [ecx]
// 007c80b2  8b4078               mov eax, dword ptr [eax + 0x78]
// 007c80b5  ffe0                 jmp eax
// library xtp-11.2.2/Source\CommandBars\XTPControl.cpp (function ?OnUnderlineActivate@CXTPControl@@UAEXXZ)

struct S {
    virtual int f();
};

int S::f() {
    int (__thiscall *p)(S *) = *(int (__thiscall **)(S *))(*(int *)this + 0x78);
    return p(this);
}
