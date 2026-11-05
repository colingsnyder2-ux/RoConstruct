// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/boost-noinline-shared-destructor
#include <boost/thread/once.hpp>
#include "v8datamodel/PhysicsService.h"
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
template<class D, const char* N>
const Name& NonFactoryProduct<D, N>::className() { return Name::declare<N>(); }

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
