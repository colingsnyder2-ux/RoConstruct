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
