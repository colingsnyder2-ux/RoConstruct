#pragma once
#include "v8tree/Service.h"
#include <set>
namespace RBX {
extern char sPhysicsService[];
class World;
class PartInstance;
struct AssemblyPhysicsOn;
struct AssemblyPhysicsOff;
class PhysicsService : public DescribedNonCreatable<PhysicsService, Instance, sPhysicsService>,
    public Service, public Listener<World, AssemblyPhysicsOn>, public Listener<World, AssemblyPhysicsOff> {
    std::set<PartInstance*> parts;
    virtual void onEvent(const World*, AssemblyPhysicsOn);
    virtual void onEvent(const World*, AssemblyPhysicsOff);
    void onAdded(PartInstance*);
    void onRemoved(PartInstance*);
    static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> eventAdded;
    static Reflection::SignalDesc<PhysicsService, void(boost::shared_ptr<Instance>)> eventRemoved;
public:
    PhysicsService();
    virtual ~PhysicsService();
};
}
