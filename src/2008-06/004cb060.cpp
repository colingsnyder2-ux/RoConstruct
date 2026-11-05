// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_physicssenderframe_31ed7530800a3409.cpp

// Candidate translation unit (score above; library headers required).
#include <G3D/CoordinateFrame.h>
struct Inner {void* data;Inner& operator=(const Inner&);};
struct S {int field0;Inner inner;double field8;G3D::CoordinateFrame frame;float f40;int f44;float f48;S* assign(S*);};
S* S::assign(S* other) {field0=other->field0;inner=other->inner;field8=other->field8;frame=other->frame;f40=other->f40;f44=other->f44;f48=other->f48;return this;}
