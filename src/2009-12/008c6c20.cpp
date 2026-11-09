// roc 2009-12 008c6c20  unit: VCEdit::?$CXTMaskEditT  size: 9 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008c6c20
//
// 008c6c20  6aff                 push -1
// 008c6c22  ff153cca9800         call dword ptr [0x98ca3c]
// 008c6c28  c3                   ret 
// copied from an identical function in another client (function ?f@S@ns_ROCX00000f@@QAEXXZ)

namespace ns_ROCX00000f {
struct S {
    void f();
};

extern "C" __declspec(dllimport) void __stdcall MessageBeep(unsigned int);

void S::f() {
    MessageBeep(0xFFFFFFFF);
}
}
