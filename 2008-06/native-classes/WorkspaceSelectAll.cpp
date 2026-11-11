// >>> native-status (generated) -- do not edit >>>
// WorkspaceSelectAll | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/1 mapped addresses byte-exact | 0 unproved | no mapped strings | by EspClaude (deepseek:deepseek-chat)
// <<< native-status | src 6b25c60c | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/PartInstance.h"

namespace RBX {

void Workspace::selectAll()
{
    ServiceClient<Selection> selection(this);
    selection->clearSelection();
    for (unsigned int i = 0; i < numChildren(); ++i) {
        Instance* child = getChild(i);
        if (dynamic_cast<IRenderable*>(child) && !PartInstance::getLocked(child))
            selection->addToSelection(child);
    }
}

}
