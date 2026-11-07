// >>> native-status (generated) -- do not edit >>>
// PhysicsServiceSignals | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 87e7264c | roc native-status --write
#include "v8datamodel/PhysicsService.h"
#include "reflection/signal.h"

RBX::Reflection::SignalDesc<RBX::PhysicsService, void(boost::shared_ptr<RBX::Instance>)>
    RBX::PhysicsService::eventAdded("AssemblyAdded", "part");
RBX::Reflection::SignalDesc<RBX::PhysicsService, void(boost::shared_ptr<RBX::Instance>)>
    RBX::PhysicsService::eventRemoved("AssemblyRemoved", "part");
