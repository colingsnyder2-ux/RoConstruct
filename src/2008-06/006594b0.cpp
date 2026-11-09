// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_sol_grid_2016helper_a4479d02850cc176.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "util/Extents.h"
extern int scaleBase;
inline float hashGridSize(int level) { return float(scaleBase<<level); }
inline G3D::Vector3 hashGridToReal(int level,const G3D::Vector3& position) { return position*hashGridSize(level); }
RBX::Extents makeBounds(int level,const G3D::Vector3& position) { RBX::Extents answer(hashGridToReal(level,position),hashGridToReal(level,position+G3D::Vector3(1,1,1))); return answer; }
