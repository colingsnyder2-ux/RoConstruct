#include "v8datamodel/ToolsPart.h"
#include "v8datamodel/ModelInstance.h"
namespace RBX {
MouseCommand* ModelSetPrimaryPartTool::onMouseDown(const UIEvent& input) {
    if (PartInstance* part = getPart(input, NULL))
        if (ModelInstance* model = dynamic_cast<ModelInstance*>(part->getTopLevelPVParent()))
            model->setPrimaryPart(part);
    return NULL;
}
}
