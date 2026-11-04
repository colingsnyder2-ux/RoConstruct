#include "v8datamodel/PhysicsService.h"
#include "reflection/signal.h"

RBX::Reflection::SignalDesc<RBX::PhysicsService, void(boost::shared_ptr<RBX::Instance>)>
    RBX::PhysicsService::eventAdded("AssemblyAdded", "part");
RBX::Reflection::SignalDesc<RBX::PhysicsService, void(boost::shared_ptr<RBX::Instance>)>
    RBX::PhysicsService::eventRemoved("AssemblyRemoved", "part");
