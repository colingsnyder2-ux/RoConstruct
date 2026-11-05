// from server: 100% by king_originala
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbxgs-dll roc_king_originala_drag_move_sdk_4f857e7feed256f1.cpp

// Candidate translation unit (score above; library headers required).
#include "tool/DragUtilities.h"
#include "util/Math.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
void DragUtilities::move(const std::vector<boost::weak_ptr<PartInstance> >& parts,G3D::CoordinateFrame from,G3D::CoordinateFrame to) {
 for(size_t i=0;i<parts.size();++i){
  boost::shared_ptr<PartInstance> part=parts[i].lock();
  if(part){
   PartInstance* object=part.get();
   G3D::CoordinateFrame coord=from.toObjectSpace(object->getCoordinateFrame());
   Math::orthonormalizeIfNecessary(coord.rotation);
   object->setCoordinateFrame(to*coord);
  }
 }
}
}
