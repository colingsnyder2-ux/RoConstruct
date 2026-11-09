// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espclaude_2a08e7f06922fadb.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Array.h"
#include "G3D/Rect2D.h"
void growRect(G3D::Array<G3D::Rect2D>& a, int n) { a.resize(n); }
