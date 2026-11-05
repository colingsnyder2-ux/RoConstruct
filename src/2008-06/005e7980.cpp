// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_fuzzyextents91875ffaee99b9e0.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <util/Extents.h>
#include <G3D/CoordinateFrame.h>
struct Body{char pad[0x94];G3D::CoordinateFrame frame;void update();const G3D::CoordinateFrame& getFrame(){update();return frame;}};
struct Geometry{virtual void f0();virtual void f1();virtual void f2();virtual void f3();virtual void f4();virtual G3D::Vector3 corner(const G3D::Matrix3&);};
struct Primitive{char pad[0x9c];Geometry*geometry;Body*body;RBX::Extents compute();};
RBX::Extents Primitive::compute(){RBX::Extents ext=RBX::Extents::fromCenterCorner(body->getFrame().translation,geometry->corner(body->getFrame().rotation));ext.expand(0.01f);return ext;}
