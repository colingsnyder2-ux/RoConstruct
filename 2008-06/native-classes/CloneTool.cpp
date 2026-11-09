// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "tool/BasicMouseTools.h"
#include "tool/PartDragTool.h"
#include "v8datamodel/Workspace.h"
#include "util/Sound.h"
#include "util/InsertMode.h"
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
char sCloneTool[] = "Clone";
CloneTool::CloneTool(Workspace* workspace) : Named<MouseCommand, sCloneTool>(workspace) {}

MouseCommand* CloneTool::isSticky() const { return new CloneTool(workspace); }

void CloneTool::onMouseIdle(const UIEvent& input)
{
    partInstance = shared_from(getUnlockedPartByLocalCharacter(input));
}

const std::string CloneTool::getCursorName() const
{
    if (partInstance) return "CloneOverCursor";
    return "CloneCursor";
}

MouseCommand* CloneTool::onMouseDown(const UIEvent& input)
{
    if (partInstance) {
        partInstance->getCoordinateFrame();
        boost::shared_ptr<PartInstance> part = boost::static_pointer_cast<PartInstance>(partInstance->clone());
        std::vector<boost::shared_ptr<Instance> > instances;
        instances.push_back(part);
        workspace->insertInstances(instances, workspace, INSERT_TO_TREE, SUPPRESS_PROMPTS);
        ServiceProvider::create<Soundscape::SoundService>(workspace)->playSound(PING_SOUND);
        return (new PartDragTool(part.get(), part->getCoordinateFrame().translation, workspace,
                                 boost::shared_ptr<Instance>()))->onMouseDown(input);
    }
    return NULL;
}

template<> const Name& Named<MouseCommand, sCloneTool>::getName() const
{
    return NativeToolName<CloneTool>::get();
}
template<> MouseCommand* TToolVerb<CloneTool, RunStateVerb>::newMouseCommand()
{
    return new CloneTool(dataModel->getWorkspace());
}
}
