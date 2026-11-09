// from server: 100% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_25082a325a5c0c98.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#define private public
#define protected public
#include "v8datamodel/ModelInstance.h"
#include "AppDraw/Draw.h"
namespace RBX {
struct ExeLocation{virtual const G3D::CoordinateFrame getLocation() const;};
struct ExeVbHolder:virtual ExeLocation{};
struct ExeModel{Extents computeExtentsRelative(const G3D::CoordinateFrame& frame) const;};
struct ExeModelSelect{void render3dSelect(Adorn*adorn,SelectState state);};
void ExeModelSelect::render3dSelect(Adorn*adorn,SelectState state){G3D::CoordinateFrame location=reinterpret_cast<const ExeVbHolder*>(reinterpret_cast<char*>(this)-0xc)->getLocation();Extents local=reinterpret_cast<const ExeModel*>(reinterpret_cast<char*>(this)-0x9c)->computeExtentsRelative(location);location.translation=location.pointToWorldSpace(local.center());Part part(Part::BLOCK_PART,local.size(),G3D::Color3::white(),location);Draw::selectionBox(part,adorn,state);}
}
