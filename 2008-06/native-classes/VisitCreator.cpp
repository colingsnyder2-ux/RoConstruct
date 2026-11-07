// >>> native-status (generated) -- do not edit >>>
// VisitCreator | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 1f5fbf06 | roc native-status --write
#include "v8datamodel/Visit.h"

namespace RBX {
template<typename Class, typename DerivedClass, const char* ClassName>
boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
{
    return Creatable<Instance>::create<Class>();
}

template boost::shared_ptr<Object> FactoryProduct<Visit, Instance, sVisit>::Creator::create() const;
}
