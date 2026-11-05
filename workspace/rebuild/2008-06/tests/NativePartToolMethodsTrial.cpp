#include "v8datamodel/ToolsPart.h"
namespace RBX {
void PartTool::onMouseHover(const UIEvent& input) {
    partInstance = shared_from(getPart(input, NULL));
}
void PartTool::render3dAdorn(Adorn* adorn) {
    if (partInstance)
        partInstance->render3dSelect(adorn, SELECT_NORMAL);
}
}
