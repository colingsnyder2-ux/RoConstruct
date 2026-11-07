// >>> native-status (generated) -- do not edit >>>
// PhysicsServiceEvents | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src ca5b4e12 | roc native-status --write
#include "v8datamodel/PhysicsService.h"
#include "v8datamodel/PartInstance.h"
#include "reflection/signal.h"
namespace RBX {
struct AssemblyPhysicsOn { Primitive* primitive; };
struct AssemblyPhysicsOff { Primitive* primitive; };
void PhysicsService::onEvent(const World*, AssemblyPhysicsOn event) { onAdded(PartInstance::fromPrimitive(event.primitive)); }
void PhysicsService::onEvent(const World*, AssemblyPhysicsOff event) { onRemoved(PartInstance::fromPrimitive(event.primitive)); }
void PhysicsService::onAdded(PartInstance* part) {
    eventAdded.fire(this, shared_from(part));
    std::pair<std::set<PartInstance*>::iterator, bool> result = parts.insert(part);
}
void PhysicsService::onRemoved(PartInstance* part) {
    parts.erase(part);
    eventRemoved.fire(this, shared_from(part));
}
}
