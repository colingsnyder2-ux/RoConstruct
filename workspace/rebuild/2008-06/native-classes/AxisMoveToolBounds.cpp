// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// AxisMoveToolBounds | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 85fbe0d3 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "tool/MegaDragger.h"
#include "tool/AxisMoveTool.h"
#include "tool/AxisMoveGrid.h"
#include "v8datamodel/Selection.h"
#include "tool/Dragger.h"
#include "tool/DragUtilities.h"
#include "util/Extents.h"
#include <algorithm>
namespace RBX {
void __cdecl collectPart(boost::shared_ptr<Instance> value, std::vector<Primitive*>* parts) { DragUtilities::getPrimitives(value.get(), *parts); }
struct AxisBoundsCallback {
    void (__cdecl* function)(boost::shared_ptr<Instance>, std::vector<Primitive*>*);
    std::vector<Primitive*>* parts;
    AxisBoundsCallback(void (__cdecl* f)(boost::shared_ptr<Instance>, std::vector<Primitive*>*), std::vector<Primitive*>* p) : function(f), parts(p) {}
    void operator()(const boost::shared_ptr<Instance>& p) { function(p, parts); }
};
bool AxisMoveTool::bounds(Extents& out) {
    ServiceClient<Selection> selection(workspace);
    std::vector<Primitive*> parts;
    std::for_each(selection->selection->begin(), selection->selection->end(), AxisBoundsCallback(collectPart, &parts));
    if (parts.size() > 0) { out = Dragger::computeExtents(parts); return true; }
    return false;
}
}
