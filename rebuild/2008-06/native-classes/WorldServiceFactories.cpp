#include <boost/thread/once.hpp>
#include "v8datamodel/PhysicsService.h"
#include "v8datamodel/JointsService.h"
namespace RBX {
extern template boost::shared_ptr<JointsService> Creatable<Instance>::create<JointsService>();
extern template boost::shared_ptr<PhysicsService> Creatable<Instance>::create<PhysicsService>();
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
template JointsService* ServiceProvider::create<JointsService>() const;
template PhysicsService* ServiceProvider::create<PhysicsService>() const;
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class boost::shared_ptr<RBX::JointsService>;
