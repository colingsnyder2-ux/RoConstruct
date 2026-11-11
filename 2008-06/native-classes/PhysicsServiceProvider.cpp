// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
// >>> native-status (generated) -- do not edit >>>
// PhysicsServiceProvider | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 2a5e073d | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Notifier<RBX::World,RBX::AssemblyPhysicsOff>;
template class RBX::Notifier<RBX::World,RBX::AssemblyPhysicsOn>;
template class std::_Vector_const_iterator<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOff> *,std::allocator<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOff> *> >;
template class std::_Vector_const_iterator<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOn> *,std::allocator<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOn> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOff> *,std::allocator<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOff> *> >;
template class std::_Vector_iterator<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOn> *,std::allocator<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOn> *> >;
template class std::vector<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOff> *,std::allocator<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOff> *> >;
template class std::vector<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOn> *,std::allocator<RBX::Listener<RBX::World,RBX::AssemblyPhysicsOn> *> >;
