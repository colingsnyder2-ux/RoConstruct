// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_explosionrendercapture7ee6b27316cddb89.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#include "RbxGraphics/Adorn.h"
#include "G3D/Sphere.h"
struct Effect {char prefix[20];G3D::Vector3 position;volatile float radius;void render(RBX::Adorn*);};
void Effect::render(RBX::Adorn* adorn){adorn->setObjectToWorldMatrix(G3D::CoordinateFrame(position));float r=radius;G3D::Sphere sphere(G3D::Vector3::zero(),r);G3D::Color4 color(G3D::Color3::red(),1.0f);adorn->explosion(sphere,color,G3D::Color4::clear());}
