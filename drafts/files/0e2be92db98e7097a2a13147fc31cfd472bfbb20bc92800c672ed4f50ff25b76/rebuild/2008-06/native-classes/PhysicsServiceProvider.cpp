// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
#include "v8datamodel/PhysicsService.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"
namespace RBX {
void PhysicsService::onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider) {
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
