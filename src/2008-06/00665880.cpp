// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_effectboxnativef8ebe80909dcc36d.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "util/Extents.h"
#include "G3D/Ray.h"
bool testEffect(const RBX::Extents&,const G3D::CoordinateFrame&,const G3D::Ray&,G3D::Vector3&,int&);
bool hit(const RBX::Extents& box,const G3D::Ray& ray,G3D::Vector3& point,int& face){G3D::CoordinateFrame frame(box.center());RBX::Extents local=RBX::Extents::fromCenterCorner(G3D::Vector3::zero(),box.size()*0.5f);return testEffect(local,frame,ray,point,face);}
