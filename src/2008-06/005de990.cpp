// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_espeon_rotationmatrixnativeec51ed70427929c5.cpp

// Candidate translation unit (score above; library headers required).
#include "G3D/Matrix3.h"
const G3D::Matrix3& firstRotation();const G3D::Matrix3& secondRotation();
G3D::Matrix3 rotation(int n){switch(n){case 0:return G3D::Matrix3(1,0,0,0,0,-1,0,1,0);case 1:return firstRotation();case 2:return G3D::Matrix3(1,0,0,0,0,1,0,-1,0);case 3:return secondRotation();default:return G3D::Matrix3::identity();}}
