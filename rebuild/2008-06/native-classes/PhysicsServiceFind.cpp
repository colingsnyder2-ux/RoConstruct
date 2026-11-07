// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
// >>> native-status (generated) -- do not edit >>>
// PhysicsServiceFind | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src f66d4dea | roc native-status --write
#include <boost/thread/once.hpp>
#include "v8datamodel/PhysicsService.h"
namespace RBX {
char sPhysicsService[] = "PhysicsService";
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
template<class Derived, const char* ClassName>
const Name& NonFactoryProduct<Derived, ClassName>::className() { return Name::declare<ClassName>(); }

template<> const Name& NonFactoryProduct<Instance, sPhysicsService>::getClassName() const {
    return className();
}

template<> PhysicsService* ServiceProvider::find<PhysicsService>() const {
    size_t index = getClassIndex<PhysicsService>();
    if (index + 1 > serviceArray.size()) {
        serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
    } else {
        PhysicsService* service = static_cast<PhysicsService*>(serviceArray[index].get());
        if (service) return service;
    }
    boost::shared_ptr<Instance> item = findServiceByClassName(PhysicsService::className());
    if (!item) return NULL;
    PhysicsService* service = static_cast<PhysicsService*>(item.get());
    serviceArray[index] = item;
    return service;
}
}
