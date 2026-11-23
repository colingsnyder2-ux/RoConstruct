// =============================================================================
// ToolsPart.cpp
// =============================================================================
// RoConstruct: matching-decompilation / source recovery of the 2008-06 Roblox client.
//   Project : https://github.com/colingsnyder2-ux/RoConstruct
//   Branch  : layout/2008-06 (organized layout, one file per original source path)
//   Path    : rebuild/2008-06/layout/client/app/v8datamodel/ToolsPart.cpp
//
// Recovered from the shipped binary and tidied for this layout. Where this file
// is a compiled unit, its object is checked identical to the live recovery source
// (same compiler and flags). Not a source-only client, a server match or a runtime gate.
// Names or fields marked "// INFERRED:" are not in the binary and rest on stated evidence.
// Hex numbers in comments are addresses in the 2008-06 binary; more notes are in
// rebuild/2008-06/layout/evidence.json.
// =============================================================================

#include "v8datamodel/ToolsPart.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ModelInstance.h"
#include "StandardVerbs.h"
#include "util/Sound.h"

namespace RBX
{
char sFillTool[] = "Fill";
char sDropperTool[] = "Dropper";
char sModelSetPrimaryPartTool[] = "ModelSetPrimaryPart";
void recordCameraHistory(const char*, const Instance*);

const std::string FillTool::getCursorName() const { return "FillCursor"; }
MouseCommand* FillTool::isSticky() const { return new FillTool(workspace); }
const std::string DropperTool::getCursorName() const { return "DropperCursor"; }

MouseCommand* FillTool::onMouseDown(const UIEvent& input)
{
    if (PartInstance* part = getPart(input, NULL)) {
        part->setColor(color.get());
        ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(SPLAT_SOUND);
        recordCameraHistory(getName().c_str(), workspace);
        workspace->getDataState().setDirty(true);
    }
    return NULL;
}

void FillToolColor::set(const BrickColor& value)
{
    if (color != value) {
        color = value;
        raise(value);
    }
}

MouseCommand* DropperTool::onMouseDown(const UIEvent& input)
{
    if (PartInstance* part = getPart(input, NULL)) {
        FillTool::color.set(part->getColor());
        ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(CLICK_SOUND);
    }
    return NULL;
}

MouseCommand* ModelSetPrimaryPartTool::onMouseDown(const UIEvent& input)
{
    if (PartInstance* part = getPart(input, NULL))
        if (ModelInstance* model = dynamic_cast<ModelInstance*>(part->getTopLevelPVParent()))
            model->setPrimaryPart(part);
    return NULL;
}

template<> const Name& Named<PartTool, sFillTool>::getName() const { return NativeToolName<FillTool>::get(); }
template<> const Name& Named<PartTool, sDropperTool>::getName() const { return NativeToolName<DropperTool>::get(); }
template<> const Name& Named<PartTool, sModelSetPrimaryPartTool>::getName() const { return NativeToolName<ModelSetPrimaryPartTool>::get(); }
}
