// >>> native-status (generated) -- do not edit >>>
// RunStateVerbConstructor | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (chatgpt:gpt-6.1-sol)
// <<< native-status | src 90a7db4d | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
RunStateVerb::RunStateVerb(std::string name, DataModel* model)
    : Verb(model, name), dataModel(model), runService(model) {}
}
