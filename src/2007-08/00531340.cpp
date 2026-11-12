// from server: 100% by EspClaude
// from server: 82% by EspClaude
// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_claude_897465697d1fce18.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <vector>
#include <util/Extents.h>
using G3D::Vector3;using G3D::CoordinateFrame;using RBX::Extents;
struct Dimensions{float unused;Vector3 value;};
struct Body{char pad[0x84];CoordinateFrame frame;void update();const CoordinateFrame&getValue(){update();return frame;}};
struct Primitive{char pad[0x60];Dimensions*dimensions;Body*body;};
struct Interface{virtual CoordinateFrame getFrame()=0;};
struct PrimitiveList:std::vector<Primitive*>{Primitive*raw(size_t i){return _Myfirst[i];}};
struct S;extern void __cdecl collect(S*,PrimitiveList*);
extern const float extentScale;
struct S{char pad[0xec];int*frameTable;Extents f();};
Extents S::f(){PrimitiveList primitives;collect(this,&primitives);Extents result(Extents::negativeInfiniteExtents());for(size_t i=0;i<primitives.size();++i){Primitive*primitive=primitives.raw(i);const CoordinateFrame&pv=primitive->body->getValue();Vector3 half=primitive->dimensions->value*0.5f;Extents bounds(-half,half);Interface*object=reinterpret_cast<Interface*>(reinterpret_cast<char*>(&frameTable)+frameTable[2]);Extents transformed=bounds.express(pv,object->getFrame());result.unionWith(transformed);}return primitives.size()>0?result:Extents::zero();}
