#include "v8datamodel/DataModel.h"
#include "StandardVerbs.h"
namespace RBX {
template<> boost::shared_ptr<Workspace> shared_from<Workspace>(Workspace*);
template<class T> ServiceClient<T>::ServiceClient(Instance* instance) : context(instance) {}
EditSelectionVerb::EditSelectionVerb(std::string name, DataModel* model)
    : Verb(model, name), workspace(shared_from(model->getWorkspace())), selection(model), dataModel(model) {}
}
