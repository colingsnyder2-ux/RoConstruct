// from server: 100% by EspClaude
// from server: 91% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /MD
// roc-lib: rbxgs-dll roc_espclaude_78e0d27bdd630643.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "util/Extents.h"
#include "G3D/Ray.h"
bool testEffect(const RBX::Extents&,const G3D::CoordinateFrame&,const G3D::Ray&,G3D::Vector3&,int&,int);
bool hit(const RBX::Extents& box,const G3D::Ray& ray,G3D::Vector3& point,int& face,int extra){G3D::Vector3 c;c=(box.min()+box.max())*0.5f;G3D::CoordinateFrame frame(c);RBX::Extents local=RBX::Extents::fromCenterCorner(G3D::Vector3::zero(),box.size()*0.5f);return testEffect(local,frame,ray,point,face,extra);}
