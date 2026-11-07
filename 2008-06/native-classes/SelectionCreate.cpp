// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// >>> native-status (generated) -- do not edit >>>
// SelectionCreate | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 3ea6ccf5 | roc native-status --write
#include <boost/thread/once.hpp>
#include "v8datamodel/Selection.h"

// Selection creation uses the independently recovered lookup provider.
namespace RBX {
template<> template<> boost::shared_ptr<Selection> Creatable<Instance>::create<Selection>();
template<class Class, class Derived, const char* Name>
const RBX::Name& FactoryProduct<Class, Derived, Name>::className() { return RBX::Name::declare<Name>(); }
template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
template<class Class> size_t ServiceProvider::getClassIndex() {
    static boost::once_flag flag = BOOST_ONCE_INIT;
    boost::call_once(&callDoGetClassIndex<Class>, flag);
    return doGetClassIndex<Class>();
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
template Selection* ServiceProvider::create<Selection>() const;
template<class Class> Class* ServiceProvider::create(const Instance* context) {
    while (context) {
        if (const ServiceProvider* provider = dynamic_cast<const ServiceProvider*>(context)) return provider->create<Class>();
        context = context->getParent();
    }
    return NULL;
}
template Selection* ServiceProvider::create<Selection>(const Instance*);

}
