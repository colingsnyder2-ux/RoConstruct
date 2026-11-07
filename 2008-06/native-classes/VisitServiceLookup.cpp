// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
// >>> native-status (generated) -- do not edit >>>
// VisitServiceLookup | 2008-06 | inactive
// unmapped (no binary link) | unmapped (no binary link) | by -
// <<< native-status | src 6fd2bead | roc native-status --write
#include "v8datamodel/Visit.h"
#include "v8tree/Service.h"

namespace RBX {
template<class Class, class DerivedClass, const char* ClassName>
const Name& FactoryProduct<Class, DerivedClass, ClassName>::className() {
    return Name::declare<ClassName>();
}
template<> const Name& Name::doDeclare<sVisit>() {
    static const Name& name = declare("Visit", -1);
    return name;
}
template<class DerivedClass, const char* ClassName>
const Name& NonFactoryProduct<DerivedClass, ClassName>::className() {
    return Name::declare<ClassName>();
}
template<> const Name& NonFactoryProduct<Instance, sVisit>::getClassName() const {
    return className();
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
template Visit* ServiceProvider::find<Visit>() const;
}
