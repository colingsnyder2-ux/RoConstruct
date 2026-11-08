// >>> native-status (generated) -- do not edit >>>
// ServiceProvider | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src a9985ce6 | roc native-status --write
#include <boost/thread/once.hpp>
#include "../../../native-headers/v8datamodel/Selection.h"
#include "util/RunStateOwner.h"

// Existing recovered ServiceProvider template, instantiated for Selection.
namespace RBX {
template<class Class, class Derived, const char* Name>
const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }
template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
template<class Class> size_t ServiceProvider::getClassIndex() {
    static boost::once_flag flag = BOOST_ONCE_INIT;
    boost::call_once(&callDoGetClassIndex<Class>, flag);
    return doGetClassIndex<Class>();
}
template<class Class> Class* ServiceProvider::find() const {
    size_t index = getClassIndex<Class>();
    Class* service;
    if (index + 1 > serviceArray.size()) {
        serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
        service = NULL;
    } else {
        service = static_cast<Class*>(serviceArray[index].get());
        if (service != NULL) return service;
    }
    boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
    if (!item) return NULL;
    service = static_cast<Class*>(item.get());
    serviceArray[index] = item;
    return service;
}
template<class Class> Class* ServiceProvider::create() const {
    Class* service = find<Class>();
    if (service == NULL) {
        boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
        service = value.get();
        size_t index = getClassIndex<Class>();
        serviceArray[index] = value;
        service->setParent(const_cast<ServiceProvider*>(this));
    }
    return service;
}
template Selection* ServiceProvider::find<Selection>() const;
template RunService* ServiceProvider::find<RunService>() const;
template RunService* ServiceProvider::create<RunService>() const;
}
