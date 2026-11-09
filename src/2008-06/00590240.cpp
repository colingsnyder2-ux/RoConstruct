// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /fp:fast
// roc-lib: rbxgs-dll roc_espeon_rootinsertnative8f1851f2d4c2cb63.cpp

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
class RootInstance{public:G3D::Vector3 computeIdeInsertPoint();void moveSafe(PartArray&,G3D::Vector3,MoveType);void moveToIdeInsertPoint(PartArray&);};
void RootInstance::moveToIdeInsertPoint(PartArray&partArray){if(partArray.size()>0){Extents extents=DragUtilities::computeExtents(partArray);G3D::Vector3 insertPoint=computeIdeInsertPoint();insertPoint=insertPoint-extents.bottomCenter();G3D::Vector3 move=Dragger::toGrid(insertPoint);moveSafe(partArray,move,MOVE_DROP);}}
}
