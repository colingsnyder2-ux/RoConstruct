// from server: 100% by EspClaude
// roc 2009-06 0060acb0  unit: RBX::RotateSelectionVerb  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0060acb0
//
// 0060acb0  56                   push esi
// 0060acb1  e8aa2b0600           call 0x66d860
// 0060acb6  8b742408             mov esi, dword ptr [esp + 8]
// 0060acba  50                   push eax
// 0060acbb  8bce                 mov ecx, esi
// 0060acbd  e8bef2e8ff           call 0x499f80
// 0060acc2  8bc6                 mov eax, esi
// 0060acc4  5e                   pop esi
// 0060acc5  c20400               ret 4
// copied from an identical function in another client (function ?f@RotateSelectionVerb@ns_ROCX000001@@QAE?AUMatrix@2@XZ)

namespace ns_ROCX000001 {
struct Matrix {
    unsigned int data[9];
    Matrix(const Matrix&);
};

extern const Matrix& __cdecl getMatrix();

struct RotateSelectionVerb {
    Matrix f();
};

Matrix RotateSelectionVerb::f() {
    return getMatrix();
}
}
