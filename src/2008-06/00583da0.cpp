// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_modelselectionextentslayoutdd41eeb2c1b69c2d.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off,push)
#define private public
#define protected public
#include "v8datamodel/ModelInstance.h"
#include "AppDraw/Draw.h"
struct ExtentsInterface{virtual void slot0();virtual void slot1();virtual void slot2();virtual void slot3();virtual void slot4();virtual void slot5();virtual void slot6();virtual void slot7();virtual void slot8();virtual void slot9();virtual void slot10();virtual void slot11();virtual void slot12();virtual void slot13();virtual void slot14();virtual void slot15();virtual void slot16();virtual void slot17();virtual void slot18();virtual void slot19();virtual void slot20();virtual void slot21();virtual RBX::Extents extents()const;};
void RBX::ModelInstance::render3dSelect(Adorn*adorn,SelectState state){Extents local=reinterpret_cast<ExtentsInterface*>(reinterpret_cast<char*>(this)-8)->extents();G3D::CoordinateFrame location=getLocation();location.translation=location.pointToWorldSpace(local.center());Part part(Part::BLOCK_PART,local.size(),G3D::Color3::white(),location);Draw::selectionBox(part,adorn,state);}
