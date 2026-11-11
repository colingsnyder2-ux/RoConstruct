// >>> native-status (generated) -- do not edit >>>
// ResizeToolFind | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src d0016108 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/ResizeTool.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
class HandleHitTest {
public:
    static bool hitTestHandleLocal(const Extents&, const G3D::CoordinateFrame&, const G3D::Ray&, G3D::Vector3&, NormalId&);
};
void ResizeTool::findTargetPV(const UIEvent& inputObject) {
    ServiceClient<Selection> selection(static_cast<Instance*>(workspace));
    std::vector<boost::shared_ptr<Instance> >::const_iterator it;
    for (it = selection->selection->begin(); it != selection->selection->end(); ++it) {
        if (PartInstance* part = dynamic_cast<PartInstance*>(it->get())) {
            G3D::Ray gridRay(getUnitMouseRay(inputObject));
            if (HandleHitTest::hitTestHandleLocal(part->getExtentsLocal(), part->getLocation(), gridRay, hitPointGrid, localNormalId)) {
                targetPV = shared_from(part);
                return;
            }
        }
    }
    targetPV.reset();
}
}
