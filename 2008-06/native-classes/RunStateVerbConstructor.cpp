#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"

namespace RBX {
RunStateVerb::RunStateVerb(std::string name, DataModel* model)
    : Verb(model, name), dataModel(model), runService(model) {}
}
