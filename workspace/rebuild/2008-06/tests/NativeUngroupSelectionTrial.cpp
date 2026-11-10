#include "StandardVerbs.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/ModelInstance.h"
namespace RBX {
template<class T> T* FilteredSelection<T>::findFirst(bool (*predicate)(T*)) {
    typename std::vector<T*>::iterator found = std::find_if(filteredSelection.begin(), filteredSelection.end(), predicate);
    if (found != filteredSelection.end()) return *found;
    return NULL;
}
template ModelInstance* FilteredSelection<ModelInstance>::findFirst(bool (*)(ModelInstance*));
static __declspec(noinline) bool hasChildren(ModelInstance* model) { return model->numChildren() > 0; }
bool UngroupSelectionVerb::isEnabled() const {
    if (!(selection->size() > 0)) return false;
    FilteredSelection<ModelInstance>* selected = ServiceProvider::create<FilteredSelection<ModelInstance> >(static_cast<const ServiceProvider*>(dataModel));
    return selected->findFirst(hasChildren) != 0;
}
}

