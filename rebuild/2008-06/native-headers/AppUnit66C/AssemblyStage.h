#pragma once
// 2008-06 native RBX::AssemblyStage (inactive), the world stage between TreeStage and SleepStage. Declared under the
// non-colliding path AppUnit66C/AssemblyStage.h: the donor v8world/AssemblyStage.h keeps the 2007 shape, and the
// native-world AssemblyStage.h is the source-derived port; a unit must not include either next to this header. Bases
// IStage / IWorldStage come from the donor v8kernel/IStage.h / v8world/IWorldStage.h (as native AppUnit668/TreeStage.h).
// Every field, slot and size below is read from the 2008-06 binary (tests/record_native_app_unit66c.py checks them):
//   RTTI     AssemblyStage 0084d1a4 -> IWorldStage -> IStage (all mdisp 0).
//   size     0x50: TreeStage() 00669870 pushes 0x50 to operator new before AssemblyStage(this, world) 0066f800.
//   slots    7: 0 scalar deleting dtor (0066f8b0, calls ~AssemblyStage 0066f790), 1 getStageType (folded
//            `mov eax, 4` 006fa3f0: ASSEMBLY_STAGE is 4 in the 2008 StageType, CleanStage2008.h; the donor IStage.h
//            numbers it 3), 2 stepWorld (0066f570), 3 IStage::getKernel (0064a390), 4 onEdgeAdded (0066f5f0),
//            5 onEdgeRemoving (0066f6e0), 6 IWorldStage::getMetric (0064a3d0).
//   ctor     0066f800: downstream = new(0x1ec) SleepStage(this, world) 0064b8e0, upstream +0x4, world +0xc, then the
//            std::set<T*> constructor 0064b2a0 at +0x10 and +0x30.
//   dtor     0066f790: vtable store, the std::set<T*> destructor 0064b230 at +0x30 then +0x10, then the donor ~IStage
//            body (delete downstream through its slot 0).
//   fields   joints +0x30: stepWorld 0066f570 walks it and calls slot 13 (`void ()`, Joints2008.h stepWorld) of
//            every element before the downstream stepWorld; onEdgeAdded 0066f5f0 inserts a JOINT edge after its slot
//            11 (Joints2008.h canStepWorld) returns true (set<T*>::insert 005e8c40 on +0x30); onEdgeRemoving 0066f6e0
//            erases it (005e9f60). +0x10 is a second std::set of pointers that no row of the unit reads besides
//            the constructor and destructor: only "std::set of a pointer type" is proven (every std::set<T*> shares
//            the 0064b2a0 / 0064b230 bodies); it is declared with Assembly* after the donor's member order and is an
//            open question in the recorder's PROPOSALS.
//            Each std::set is 0x20 bytes under these flags (VS2008 RTM _SECURE_SCL).
#include <set>
#include "v8world/IWorldStage.h"

struct NativeAppUnit66CLayout;

namespace RBX
{
	class Assembly;
	class Edge;
	class Joint;
	class World;

	class AssemblyStage : public IWorldStage
	{
		friend struct ::NativeAppUnit66CLayout; // tests/record_native_app_unit66c.py offset probes

	private:
		std::set<Assembly*> assemblies;         // +0x10 (only the pointer-set shape is proven)
		std::set<Joint*> joints;                // +0x30

	public:
		AssemblyStage(IStage* upstream, World* world);      // 0066f800 (needs a 2008 SleepStage: not built)
		~AssemblyStage();                                   // 0066f790

		virtual StageType getStageType();                   // slot 1 (006fa3f0; not built, see the recorder)
		virtual void stepWorld(int worldStepId, int uiStepId, bool throttling);   // slot 2 (0066f570)
		virtual void onEdgeAdded(Edge* e);                  // slot 4 (0066f5f0; not built)
		virtual void onEdgeRemoving(Edge* e);               // slot 5 (0066f6e0; not built)

		void wakeAssembly(Assembly* assembly);              // 0066f510 (SleepStage 0064b890; not built)
		void onAssemblyAdded(Assembly* assembly);           // 0066f530 (SleepStage 0064aff0; not built)
		void onAssemblyRemoving(Assembly* assembly);        // 0066f550 (SleepStage 0064b0a0; not built)
	};
}
