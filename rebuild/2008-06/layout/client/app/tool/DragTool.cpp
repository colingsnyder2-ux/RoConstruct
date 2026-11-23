// =============================================================================
// DragTool.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/tool/DragTool.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "tool/DragTool.h"
#include "tool/PartDragTool.h"
#include "tool/GroupDragTool.h"
#include "v8datamodel/PartInstance.h"
#include <boost/weak_ptr.hpp>

namespace RBX
{
void collectDragParts(const std::vector<Instance*>&, std::vector<boost::weak_ptr<PartInstance> >&);

MouseCommand* DragTool::onMouseDown(PartInstance* hitPart, const G3D::Vector3& hitWorld,
    const std::vector<Instance*>& instances, const UIEvent& input, Workspace* workspace,
    boost::shared_ptr<Instance> decal)
{
    std::vector<boost::weak_ptr<PartInstance> > parts;
    collectDragParts(instances, parts);
    if (parts.size() == 1)
        return static_cast<MouseCommand*>(new PartDragTool(hitPart, hitWorld, workspace, decal))->onMouseDown(input);
    else
        return static_cast<MouseCommand*>(new GroupDragTool(hitPart, hitWorld, parts, workspace))->onMouseDown(input);
}
}
