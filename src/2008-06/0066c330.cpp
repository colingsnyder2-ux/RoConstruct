// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_snapinfosurfaced77d1a017aa1fdfb.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include "G3D/CoordinateFrame.h"
#include "util/Extents.h"
struct Dimensions{unsigned tag;G3D::Vector3 size;};
struct Primitive{char padding[0x9c];Dimensions*dimensions;const G3D::CoordinateFrame&getFrame();};
struct SnapInfo{Primitive*snap;RBX::NormalId surface;G3D::Vector3 hitWorld;void update();};
void SnapInfo::update(){
 G3D::Vector3 local=snap->getFrame().pointToObjectSpace(hitWorld);
 G3D::Vector3 half=snap->dimensions->size*0.5f;
 RBX::Extents extents(-half,half);
 surface=extents.closestFace(local);
}
