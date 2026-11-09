// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_framecompositionabi_f7856737efd6b30e.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
extern void __cdecl multiply(const G3D::Matrix3&,const G3D::Matrix3&,G3D::Matrix3&);
void __cdecl transform(const G3D::CoordinateFrame* a,const G3D::CoordinateFrame* b,G3D::CoordinateFrame* out) {
 multiply(a->rotation,b->rotation,out->rotation);
 out->translation=a->pointToWorldSpace(b->translation);
}
