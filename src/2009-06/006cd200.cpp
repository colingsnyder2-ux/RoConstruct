// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_d02c5a6dcd78a985.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "util/Extents.h"
#include "G3D/Ray.h"
struct Input;bool pick(const RBX::Extents&,const G3D::Ray&,G3D::Vector3&,RBX::NormalId&,int);
struct Tool{bool bounds(RBX::Extents&);G3D::Ray ray(Input*);bool hit(Input*,G3D::Vector3&,RBX::NormalId&);};
bool Tool::hit(Input*input,G3D::Vector3&result,RBX::NormalId&face){RBX::Extents box;if(bounds(box)){if(pick(box,ray(input),result,face,0x3f))return true;}return false;}

