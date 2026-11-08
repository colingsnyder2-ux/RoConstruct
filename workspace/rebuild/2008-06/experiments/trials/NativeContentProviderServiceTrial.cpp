#define NATIVE_CONTENT_PROVIDER_TYPES_ONLY
#include "NativeContentProviderTrial.cpp"
#include "v8tree/Service.h"

namespace RBX {
#ifndef SERVICE_CONTENT_CREATE_ONLY
template<> const Name& Name::doDeclare<sContentProvider>() {
    static const Name& name = declare("ContentProvider", -1);
    return name;
}
#endif
template<class DerivedClass, const char* ClassName>
const Name& NonFactoryProduct<DerivedClass, ClassName>::className() {
    return Name::declare<ClassName>();
}
#ifndef SERVICE_CONTENT_CREATE_ONLY
template<> const Name& NonFactoryProduct<Instance, sContentProvider>::getClassName() const {
    return className();
}
#endif
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
#ifndef SERVICE_CONTENT_CREATE_ONLY
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
template ContentProvider* ServiceProvider::find<ContentProvider>() const;
#endif
#ifndef SERVICE_CONTENT_FIND_ONLY
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
template ContentProvider* ServiceProvider::create<ContentProvider>() const;
#endif
}
