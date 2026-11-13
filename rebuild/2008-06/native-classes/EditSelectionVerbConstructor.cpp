// >>> native-status (generated) -- do not edit >>>
// EditSelectionVerbConstructor | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 0a9e0d13 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
template<> boost::shared_ptr<Workspace> shared_from<Workspace>(Workspace*);

EditSelectionVerb::EditSelectionVerb(std::string name, DataModel* model)
    : Verb(model, name), workspace(shared_from(model->getWorkspace())), selection(model), dataModel(model) {}
}
