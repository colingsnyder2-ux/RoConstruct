#include "NativeModelToolsTrial.h"
namespace RBX {
Instance* nativeFindUnanchoredPart(Instance*);
void AnchorTool::onMouseHover(const UIEvent& input) {
    boost::shared_ptr<Instance> previous = target;
    ModelTool::onMouseHover(input);
    if (previous != target) {
        bool value = target ? nativeFindUnanchoredPart(target.get()) == NULL : false;
        anchored = value;
    }
}
}
