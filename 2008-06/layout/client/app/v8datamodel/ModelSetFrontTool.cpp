// =============================================================================
// ModelSetFrontTool.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/ModelSetFrontTool.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "tool/SurfaceTools.h"
#include "v8datamodel/Surface.h"
#include "v8datamodel/PartInstance.h"
#include "v8datamodel/ModelInstance.h"
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
#include "util/Math.h"

namespace RBX
{
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
