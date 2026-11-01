#include <boost/thread/once.hpp>
#pragma include_alias("util/Name.h", "../roc_name_native_declare_header_cb8db0995b353ca7.cpp")
#include "../native-headers/v8datamodel/Selection.h"

// Existing recovered ServiceProvider template, instantiated for Selection.
namespace RBX {
template<class Class, class Derived, const char** Name>
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
template Selection* ServiceProvider::find<Selection>() const;
}
