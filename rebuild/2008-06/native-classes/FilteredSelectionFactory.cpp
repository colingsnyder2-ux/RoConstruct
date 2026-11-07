// >>> native-status (generated) -- do not edit >>>
// FilteredSelectionFactory | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 76fe6f5e | roc native-status --write
#include <boost/thread/once.hpp>
#include "v8datamodel/Selection.h"
#include "v8datamodel/PVInstance.h"
#include "v8datamodel/ModelInstance.h"

namespace RBX {
template<class Class> size_t ServiceProvider::doGetClassIndex() {
    static size_t index = newIndex();
    return index;
}
template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
template<class Class> size_t ServiceProvider::getClassIndex() {
    static boost::once_flag flag = BOOST_ONCE_INIT;
    boost::call_once(&callDoGetClassIndex<Class>, flag);
    return doGetClassIndex<Class>();
}
template<class Class> Class* ServiceProvider::find() const {
    size_t index = getClassIndex<Class>();
    if (index + 1 > serviceArray.size()) serviceArray.resize(index + 1);
    else {
        Class* service = static_cast<Class*>(serviceArray[index].get());
        if (service) return service;
    }
    // These two original specializations have no class-name fallback.
    // The unreachable tail preserves their original exception-handling codegen.
    if (true) return NULL;
    boost::shared_ptr<Instance> item;
    if (!item) return NULL;
    serviceArray[index] = item;
    return static_cast<Class*>(item.get());
}
template FilteredSelection<ModelInstance>* ServiceProvider::find<FilteredSelection<ModelInstance> >() const;
template FilteredSelection<PVInstance>* ServiceProvider::find<FilteredSelection<PVInstance> >() const;
template<class Class> Class* ServiceProvider::create() const {
    Class* service = find<Class>();
    if (!service) {
        boost::shared_ptr<Class> value = Creatable<Instance>::create<Class>();
        service = value.get();
        size_t index = getClassIndex<Class>();
        serviceArray[index] = value;
        service->setParent(const_cast<ServiceProvider*>(this));
    }
    return service;
}
template FilteredSelection<ModelInstance>* ServiceProvider::create<FilteredSelection<ModelInstance> >() const;
template FilteredSelection<PVInstance>* ServiceProvider::create<FilteredSelection<PVInstance> >() const;
}
