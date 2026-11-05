// from server: 100% by Espeon
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll roc_espeon_physicsservicenativeconstructorcfa29528d50b74b1.cpp

// Candidate translation unit (score above; library headers required).
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include <set>
namespace RBX {
extern const char sPhysicsService[];
class World;
struct AssemblyPhysicsOn;
struct AssemblyPhysicsOff;
class PartInstance;
class PhysicsService : public DescribedNonCreatable<PhysicsService,Instance,sPhysicsService>, public Service, public Listener<World,AssemblyPhysicsOn>, public Listener<World,AssemblyPhysicsOff> {
 std::set<PartInstance*> parts;
 virtual void onEvent(const World*,AssemblyPhysicsOn);
 virtual void onEvent(const World*,AssemblyPhysicsOff);
 public: PhysicsService(); virtual ~PhysicsService();
};
PhysicsService::PhysicsService() {setName("PhysicsService");}
}
