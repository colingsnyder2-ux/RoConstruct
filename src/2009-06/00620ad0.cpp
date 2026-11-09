// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espclaude_cddf49161268dd7e.cpp

// Candidate translation unit (score above; library headers required).
#pragma float_control(precise,off)
#include <vector>
#include <boost/weak_ptr.hpp>
#include <util/Extents.h>
namespace RBX {
class PartInstance;
typedef std::vector<boost::weak_ptr<PartInstance> > PartArray;
class DragUtilities{public:static Extents computeExtents(const PartArray&);};
class Dragger{public:static G3D::Vector3 toGrid(const G3D::Vector3&);};
enum MoveType{MOVE_DROP=0};
class RootInstance{public:G3D::Vector3 computeIdeInsertPoint();void moveSafe(PartArray&,G3D::Vector3,MoveType);void moveToInsertPoint(PartArray&,const G3D::Vector3&);};
void RootInstance::moveToInsertPoint(PartArray&partArray,const G3D::Vector3&insertPoint){if(partArray.size()>0){Extents extents=DragUtilities::computeExtents(partArray);G3D::Vector3 delta=insertPoint-extents.bottomCenter();G3D::Vector3 move=Dragger::toGrid(delta);moveSafe(partArray,move,MOVE_DROP);}}
}
