// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_modelhalfextents2ff61b80527f6eb0.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <vector>
#include <util/Extents.h>
using G3D::Vector3;using G3D::CoordinateFrame;using RBX::Extents;
struct Dimensions{float unused;Vector3 value;};
struct Primitive{char pad[0x9c];Dimensions*dimensions;void*body;const CoordinateFrame&getValue();};
struct Interface{virtual CoordinateFrame getFrame()=0;};
struct PrimitiveList:std::vector<Primitive*>{Primitive*raw(size_t i){return _Myfirst[i];}};
struct S;extern void __cdecl collect(S*,PrimitiveList*);
extern const float extentScale;
struct S{char pad[0x134];int*frameTable;Extents f();};
Extents S::f(){PrimitiveList primitives;collect(this,&primitives);Extents result(Extents::negativeInfiniteExtents());for(size_t i=0;i<primitives.size();++i){Vector3 half=primitives[i]->dimensions->value*0.5f;Primitive*primitive=primitives.raw(i);Extents bounds(-half,half);Interface*object=reinterpret_cast<Interface*>(reinterpret_cast<char*>(&frameTable)+frameTable[2]);Extents transformed=bounds.express(primitive->getValue(),object->getFrame());result.unionWith(transformed);}return primitives.size()>0?result:Extents::zero();}
