#include "v8datamodel/DataModel.h"
#include "NativeGameToolTrial.h"
#include "StandardVerbs.h"
namespace RBX {
template<> MouseCommand* TToolVerb<GameTool,RunStateVerb>::newMouseCommand() {
    return new GameTool(this->dataModel->getWorkspace());
}
}
