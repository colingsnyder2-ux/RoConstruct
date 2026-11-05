#include "v8datamodel/Visit.h"

namespace RBX {
template<typename Class, typename DerivedClass, const char* ClassName>
boost::shared_ptr<Object> FactoryProduct<Class, DerivedClass, ClassName>::Creator::create() const
{
    return Creatable<Instance>::create<Class>();
}

template boost::shared_ptr<Object> FactoryProduct<Visit, Instance, sVisit>::Creator::create() const;
}
