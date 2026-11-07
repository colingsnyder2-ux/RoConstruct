// >>> native-status (generated) -- do not edit >>>
// EditSelectionVerbConstructor | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 0a9e0d13 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
template<> boost::shared_ptr<Workspace> shared_from<Workspace>(Workspace*);

EditSelectionVerb::EditSelectionVerb(std::string name, DataModel* model)
    : Verb(model, name), workspace(shared_from(model->getWorkspace())), selection(model), dataModel(model) {}
}
