// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: openrbx-client-dll roc_espeon_extentlistworldb3dc902fa6fee311.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <G3D/Vector3.h>
#include <G3D/CoordinateFrame.h>
#include <vector>
using G3D::Vector3;
struct Extents {
 Vector3 low,high;
 Extents(const Vector3& l,const Vector3& h):low(l),high(h){}
 Extents(const Extents& e):low(e.low),high(e.high){}
 Extents toWorldSpace(const G3D::CoordinateFrame&);
 void unionWith(const Extents&);
};
extern const Extents& negativeInfiniteExtents();
struct Geometry {unsigned header;Vector3 size;};
struct Primitive {char pad[0x9c];Geometry* geometry;const G3D::CoordinateFrame& getFrame();};
struct List {std::vector<Primitive*> items;};
Extents computeExtents(const List* list){
 Extents result=negativeInfiniteExtents();
 for(unsigned i=0;i<list->items.size();++i){
  Primitive* p=list->items[i];
  Vector3 half=p->geometry->size * 0.5f;
  Extents world=Extents(-half,half).toWorldSpace(p->getFrame());
  result.unionWith(world);
 }
 return result;
}
