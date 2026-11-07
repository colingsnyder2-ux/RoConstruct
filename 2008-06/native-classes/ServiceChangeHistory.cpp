// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor /DSERVICE_HISTORY_FIND_ONLY
// >>> native-status (generated) -- do not edit >>>
// ServiceChangeHistory | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src d78fbab4 | roc native-status --write
#include <boost/thread/once.hpp>
#include "v8datamodel/ChangeHistoryService.h"

namespace RBX {
#ifndef SERVICE_HISTORY_CREATE_ONLY
template<> const Name& Name::doDeclare<sChangeHistoryService>() {
    static const Name& name = declare("ChangeHistoryService", -1);
    return name;
}
#endif
template<class Class, class DerivedClass, const char* ClassName>
const Name& FactoryProduct<Class, DerivedClass, ClassName>::className() {
    return Name::declare<ClassName>();
}
#ifndef SERVICE_HISTORY_CREATE_ONLY
template<> const Name& FactoryProduct<ChangeHistoryService, Instance, sChangeHistoryService>::getClassName() const {
    return className();
}
#endif
template<class DerivedClass, const char* ClassName>
const Name& NonFactoryProduct<DerivedClass, ClassName>::className() {
    return Name::declare<ClassName>();
}
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
#ifndef SERVICE_HISTORY_CREATE_ONLY
template<class Class> Class* ServiceProvider::find() const {
    size_t index = getClassIndex<Class>();
    Class* service;
    if (index + 1 > serviceArray.size()) {
        serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
        service = NULL;
    } else {
        service = static_cast<Class*>(serviceArray[index].get());
        if (service) return service;
    }
    boost::shared_ptr<Instance> item = findServiceByClassName(Class::className());
    if (!item) return NULL;
    service = static_cast<Class*>(item.get());
    serviceArray[index] = item;
    return service;
}
template ChangeHistoryService* ServiceProvider::find<ChangeHistoryService>() const;
#endif
#ifndef SERVICE_HISTORY_FIND_ONLY
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
template ChangeHistoryService* ServiceProvider::create<ChangeHistoryService>() const;
#endif
}
