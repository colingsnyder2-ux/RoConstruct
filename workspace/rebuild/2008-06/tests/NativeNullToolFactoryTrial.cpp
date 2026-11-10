#include "v8datamodel/DataModel.h"
#include "tool/NullTool.h"
#include "StandardVerbs.h"
namespace RBX {
typedef char NullToolSize[sizeof(NullTool)==0x1c ? 1 : -1];
template<> MouseCommand* TToolVerb<NullTool,RunStateVerb>::newMouseCommand() {
    return new NullTool(this->dataModel->getWorkspace());
}
}
