// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// PartTools | 2008-06 | draft (no current byte proof)
// 0/6 mapped addresses byte-exact | 6 unproved | no mapped strings | by king_originala (+1) (mixed 2)
// <<< native-status | src 7e1d95a6 | roc native-status --write
#include "v8datamodel/ToolsPart.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/ModelInstance.h"
#include "StandardVerbs.h"
#include "util/Sound.h"

namespace RBX {
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
