// >>> native-status (generated) -- do not edit >>>
// FilteredSelectionMethods | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 228258b4 | roc native-status --write
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/ModelInstance.h"

namespace RBX {
template<class T> T* FilteredSelection<T>::findFirst(bool (*predicate)(T*)) {
    typename std::vector<T*>::iterator found = std::find_if(filteredSelection.begin(), filteredSelection.end(), predicate);
    if (found != filteredSelection.end()) return *found;
    return NULL;
}

template ModelInstance* FilteredSelection<ModelInstance>::findFirst(bool (*)(ModelInstance*));
template PVInstance* FilteredSelection<PVInstance>::findFirst(bool (*)(PVInstance*));
}
