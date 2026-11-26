// from server: 100% by Xemicl
// roc 2012-06 006f2d20  unit: RBX::RotateSelectionVerb  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f2d20
//
// 006f2d20  56                   push esi
// 006f2d21  e8daa90c00           call 0x7bd700
// 006f2d26  8b742408             mov esi, dword ptr [esp + 8]
// 006f2d2a  50                   push eax
// 006f2d2b  8bce                 mov ecx, esi
// 006f2d2d  e81e95f3ff           call 0x62c250
// 006f2d32  8bc6                 mov eax, esi
// 006f2d34  5e                   pop esi
// 006f2d35  c20400               ret 4
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