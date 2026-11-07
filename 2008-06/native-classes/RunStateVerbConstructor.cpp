// >>> native-status (generated) -- do not edit >>>
// RunStateVerbConstructor | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 90a7db4d | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
RunStateVerb::RunStateVerb(std::string name, DataModel* model)
    : Verb(model, name), dataModel(model), runService(model) {}
}
