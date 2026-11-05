#include <boost/thread/once.hpp>
#include "v8tree/Service.h"
#include "v8datamodel/JointsService.h"
#if defined(WORLD_EVENT_PROFILE) || defined(WORLD_ACTION_PROFILE)
#include "v8datamodel/PartInstance.h"
#endif
#ifdef WORLD_ACTION_PROFILE
#include "reflection/signal.h"
#endif
#include <set>

namespace RBX {
extern char sPhysicsService[];
class World;
class PartInstance;
class Primitive;
#ifdef WORLD_EVENT_PROFILE
struct AssemblyPhysicsOn { Primitive* primitive; };
struct AssemblyPhysicsOff { Primitive* primitive; };
#else
struct AssemblyPhysicsOn;
struct AssemblyPhysicsOff;
#endif
class PhysicsService : public DescribedNonCreatable<PhysicsService, Instance, sPhysicsService>,
    public Service, public Listener<World, AssemblyPhysicsOn>, public Listener<World, AssemblyPhysicsOff> {
    std::set<PartInstance*> parts;
    virtual void onEvent(const World*, AssemblyPhysicsOn);
    virtual void onEvent(const World*, AssemblyPhysicsOff);
    void onAdded(PartInstance*);
    void onRemoved(PartInstance*);
#ifdef WORLD_ACTION_PROFILE
    static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> eventAdded;
    static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> eventRemoved;
#endif
public:
    PhysicsService();
    virtual ~PhysicsService();
};
#ifdef WORLD_LIFETIME_PROFILE
PhysicsService::PhysicsService() { setName("PhysicsService"); }
PhysicsService::~PhysicsService() {}
#endif
#ifdef WORLD_ACTION_PROFILE
#ifndef WORLD_EXCLUDE_ADDED
void PhysicsService::onAdded(PartInstance* part) {
    eventAdded.fire(this, shared_from(part));
    parts.insert(part);
}
#endif
void PhysicsService::onRemoved(PartInstance* part) {
    parts.erase(part);
    eventRemoved.fire(this, shared_from(part));
}
#endif
#ifdef WORLD_EVENT_PROFILE
void PhysicsService::onEvent(const World*, AssemblyPhysicsOn event) { onAdded(PartInstance::fromPrimitive(event.primitive)); }
void PhysicsService::onEvent(const World*, AssemblyPhysicsOff event) { onRemoved(PartInstance::fromPrimitive(event.primitive)); }
#endif

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
#if defined(WORLD_FIND_PROFILE) || defined(WORLD_JOINTS_FIND_PROFILE)
template<> JointsService* ServiceProvider::find<JointsService>() const {
    size_t index = getClassIndex<JointsService>();
    if (index + 1 > serviceArray.size()) {
        serviceArray.resize(index + 1, boost::shared_ptr<Instance>());
    } else {
        JointsService* service = static_cast<JointsService*>(serviceArray[index].get());
        if (service) return service;
    }
    // The original non-factory service has no class name; the generic
    // name-lookup branch is unreachable for this specialization.
    if (true) return NULL;
    boost::shared_ptr<Instance> item;
    if (!item) return NULL;
    serviceArray[index] = item;
    return static_cast<JointsService*>(item.get());
}
#endif
#if defined(WORLD_FIND_PROFILE) || defined(WORLD_PHYSICS_FIND_PROFILE)
template<class Derived, const char* ClassName>
const Name& NonFactoryProduct<Derived, ClassName>::className() {
    return Name::declare<ClassName>();
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
#ifndef WORLD_PHYSICS_FIND_PROFILE
template JointsService* ServiceProvider::create<JointsService>() const;
template PhysicsService* ServiceProvider::create<PhysicsService>() const;
#endif
}
