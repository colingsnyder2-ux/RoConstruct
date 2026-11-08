// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// ModelSetFrontTool | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 2de4e42e | roc native-status --write
#include "tool/SurfaceTools.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
#include "util/Math.h"

namespace RBX {
char sModelSetFrontTool[] = "ModelSetFront";
const std::string ModelSetFrontTool::getCursorName() const { return "DirectionCursor"; }
MouseCommand* ModelSetFrontTool::isSticky() const { return NULL; }
void ModelSetFrontTool::applyToSurface(Surface* surface)
{
    PartInstance* part = surface->getPartInstance();
    if (ModelInstance* model = dynamic_cast<ModelInstance*>(part->getTopLevelPVParent()))
        model->setFrontAndTop(Math::getWorldNormal(surface->getNormalId(), part->getCoordinateFrame()));
}
template<> const Name& Named<SurfaceTool, sModelSetFrontTool>::getName() const
{
    return NativeToolName<ModelSetFrontTool>::get();
}
template<> MouseCommand* TToolVerb<ModelSetFrontTool, RunStateVerb>::newMouseCommand()
{
    return new ModelSetFrontTool(dataModel->getWorkspace());
}
}
