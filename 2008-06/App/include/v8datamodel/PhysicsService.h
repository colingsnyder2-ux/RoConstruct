#pragma once
// >>> native-status (generated) -- do not edit >>>
// PhysicsService | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 7b207a58 | roc native-status --write
// 2008-06 native RBX::PhysicsService (inactive). No donor header; names after the existing probe
// tests/record_native_physics_array_lifetime.py. Every base, field and virtual below is read from the 2008-06 binary:
//   RTTI       vtable 00826aac .?AVPhysicsService@RBX@@ -> DescribedNonCreatable<PhysicsService, Instance,
//              sPhysicsService> (name mangled $1?sPhysicsService@2@3QBDB: a const char array in .rdata at 0083f858
//              holding "PhysicsService"), Listener<World, AssemblyPhysicsOn> (mdisp 0x130, vtable 00826a24:
//              onEvent 005e9110), Listener<World, AssemblyPhysicsOff> (mdisp 0x134, vtable 00826a18: onEvent
//              005e9130) and the empty Service (mdisp 0x138). AssemblyPhysicsOn/Off are structs in RBX
//              (RTTI U prefix) that the native World.h does not declare yet: forward-declared here.
//   size       0x158: Creatable<Instance>::create<PhysicsService> 004cd760 allocates 0x158; the constructor 004cd5b0
//              calls the DescribedNonCreatable constructor 004cd510, stores the twelve vtables, builds
//              std::set<PartInstance*> at +0x138 (_Tree(const less&, const allocator&) 0064b2a0; head +0x150, size
//              +0x154) and calls setName("PhysicsService") (string 00826a04).
//   dtor       005e8d30 (out of line, PhysicsService unit): ~set 0064b230 on +0x138, ~Instance 0055a540; the deleting
//              destructor 004cd740 and the ten ??_E thunks 004cd6a0..004cd730 sit next to the constructor.
//   vtable     slot 12 onServiceProvider 005e8ec0 (Workspace world +0x2e4: Notifier<World, AssemblyPhysicsOn> at
//              World +0x40, Notifier<World, AssemblyPhysicsOff> at +0x60; no Instance::onServiceProvider call).
//   events     onEvent(AssemblyPhysicsOn) 005e9110 -> onAdded 005e8f70 (fires AssemblyAdded 0097abec, inserts the
//              part: set insert 005e8c40); onEvent(AssemblyPhysicsOff) 005e9130 -> onRemoved 005e9040 (erase
//              005e9f60, fires AssemblyRemoved 0097ac20). Both convert with PartInstance::fromPrimitive 00599f80.
#include "v8tree/Instance.h"
#include "v8tree/Service.h"
#include "reflection/reflection.h"
#include <set>

struct NativeServicesLayout;

namespace RBX
{
	class World;
	class PartInstance;
	struct AssemblyPhysicsOn;
	struct AssemblyPhysicsOff;

	extern const char sPhysicsService[];

	class PhysicsService : public DescribedNonCreatable<PhysicsService, Instance, sPhysicsService>,
						   public Service,
						   public Listener<World, AssemblyPhysicsOn>,
						   public Listener<World, AssemblyPhysicsOff>
	{
		friend struct ::NativeServicesLayout; // tests/NativeServicesLayout.cpp offset asserts

	private:
		std::set<PartInstance*> parts;                                    // +0x138

		void onAdded(PartInstance* part);                                 // 005e8f70
		void onRemoved(PartInstance* part);                               // 005e9040

	protected:
		virtual void onServiceProvider(const ServiceProvider* oldProvider, const ServiceProvider* newProvider); // 005e8ec0
		virtual void onEvent(const World* source, AssemblyPhysicsOn event);  // 005e9110
		virtual void onEvent(const World* source, AssemblyPhysicsOff event); // 005e9130

	public:
		PhysicsService()                                                  // 004cd5b0
		{
			setName("PhysicsService");
		}
		~PhysicsService();                                                // 005e8d30 (deleting 004cd740)
	};
}
