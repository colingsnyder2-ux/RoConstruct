#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/JointsService.h"
#include <set>

namespace RBX {
extern const char* sPhysicsService;
class World;
class PartInstance;
struct AssemblyPhysicsOn;
struct AssemblyPhysicsOff;
class PhysicsService : public DescribedNonCreatable<PhysicsService, Instance, &sPhysicsService>,
    public Service, public Listener<World, AssemblyPhysicsOn>, public Listener<World, AssemblyPhysicsOff> {
    std::set<PartInstance*> parts;
    virtual void onEvent(const World*, AssemblyPhysicsOn);
    virtual void onEvent(const World*, AssemblyPhysicsOff);
public:
    PhysicsService();
    virtual ~PhysicsService();
};

extern template boost::shared_ptr<JointsService> Creatable<Instance>::create<JointsService>();
#ifdef WORLD_ALLOCATION_PROFILE
template boost::shared_ptr<PhysicsService> Creatable<Instance>::create<PhysicsService>();
#else
extern template boost::shared_ptr<PhysicsService> Creatable<Instance>::create<PhysicsService>();
#endif
template<class Class> size_t ServiceProvider::doGetClassIndex() { static size_t index = newIndex(); return index; }
template<class Class> void ServiceProvider::callDoGetClassIndex() { doGetClassIndex<Class>(); }
template<class Class> size_t ServiceProvider::getClassIndex() {
    static boost::once_flag flag = BOOST_ONCE_INIT;
    boost::call_once(&callDoGetClassIndex<Class>, flag);
    return doGetClassIndex<Class>();
}
#ifdef WORLD_FIND_PROFILE
template<> JointsService* ServiceProvider::find<JointsService>() const {
    size_t index = getClassIndex<JointsService>();
    if (index + 1 > serviceArray.size()) {
        serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
    } else {
        JointsService* service = static_cast<JointsService*>(serviceArray[index].get());
        if (service) return service;
    }
    return NULL;
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
#endif
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
