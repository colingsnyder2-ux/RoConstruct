// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
#include "v8world/World.h"
#include "v8datamodel/PhysicsService.h"
#include "v8datamodel/Workspace.h"

namespace RBX {
// Only the four RTTI-proven World notifier bases are used here.
// The engine-world profile's complete World lifetime remains unproven.
void PhysicsService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider)
{
    if (Workspace* workspace = ServiceProvider::find<Workspace>(oldProvider)) {
        World* world = workspace->getWorld();
        Notifier<World, AssemblyPhysicsOn>::disconnect(world, this);
        Notifier<World, AssemblyPhysicsOff>::disconnect(world, this);
    }
    if (Workspace* workspace = ServiceProvider::find<Workspace>(newProvider)) {
        World* world = workspace->getWorld();
        Notifier<World, AssemblyPhysicsOn>::connect(world, this);
        Notifier<World, AssemblyPhysicsOff>::connect(world, this);
    }
}
}
