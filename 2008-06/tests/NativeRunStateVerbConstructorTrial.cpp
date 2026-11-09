#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
namespace RBX {
template<> ServiceClient<RunService>::ServiceClient(Instance* instance) : context(instance) {}
RunStateVerb::RunStateVerb(std::string name, DataModel* model)
    : Verb(model, name), dataModel(model), runService(model) {}
}
