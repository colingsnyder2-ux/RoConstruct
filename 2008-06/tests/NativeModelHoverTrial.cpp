#include "NativeModelToolTrial.h"
#include "v8datamodel/PartInstance.h"
namespace RBX {
void ModelTool::onMouseHover(const UIEvent& input) {
    if (PartInstance* part = getPart(input, NULL))
        target = shared_from(Workspace::findTopInstance(part));
    else
        target.reset();
}
}
