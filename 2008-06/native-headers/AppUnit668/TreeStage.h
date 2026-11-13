#pragma once
// 2008-06 native RBX::TreeStage (inactive), the world stage between ClumpStage and AssemblyStage. No donor header
// declares it (the donor v8world/ClumpStage.h has only ClumpStage), so it lives under the non-colliding path
// AppUnit668/TreeStage.h and shadows nothing. Bases IStage / IWorldStage come from the donor v8kernel/IStage.h /
// v8world/IWorldStage.h, as for the native CleanStage2008.h / JointStage2008.h. A unit must not also include
// native-world/App/include/v8world/ClumpStage.h (the source-derived port's 0x30-byte TreeStage).
// Every field, slot and size below is read from the 2008-06 binary (tests/record_native_app_unit668.py checks them):
//   RTTI     TreeStage 0084cf94 -> IWorldStage -> IStage (all mdisp 0).
//   size     0x78: ClumpStage(upstream, world) 0064cfd0 pushes 0x78 to operator new before TreeStage(this, world)
//            00669870.
//   slots    7: 0 scalar deleting dtor (00669760, calls ~TreeStage 00669390), 1 getStageType (folded `mov eax, 3`
//            005e2790: TREE_STAGE is 3 in the 2008 StageType, CleanStage2008.h), 2 stepWorld (00669780), 3
//            IStage::getKernel (0064a390), 4 onEdgeAdded (00669c00), 5 onEdgeRemoving (00669c70), 6 getMetric
//            (00669030).
//   ctor     00669870: downstream = new(0x50) AssemblyStage(this, world) 0066f800, upstream +0x4, world +0xc,
//            +0x10 = 0 (int), +0x14 = false (byte), then the set<T*> constructor 0064b2a0 at +0x18, +0x38 and +0x58.
//   dtor     00669390: vtable store, the set<T*> destructor 0064b230 at +0x58, +0x38, +0x18, then the donor ~IStage
//            body (delete downstream through its slot 0).
//   fields   maxTreeDepth +0x10 (getMetric 00669030 returns it for metric 3 = MAX_TREE_DEPTH; 006697a0 raises it to
//            the depth argument), dirty +0x14 (set after every insert into +0x38 / +0x58, cleared by process 00669410),
//            assemblies +0x38 (dirtyAssemblies 00669240 inserts Primitive::getAssembly() 005e7570 of each joint
//            primitive; process walks it with cleanAssembly 00668f20 and clears it), edges +0x58 (process erases it
//            with cleanEdge 00668fa0 while +0x74 (its size) is non-zero; 00669340 inserts an Edge after testing the
//            edge's inEdgeList +0x1c). +0x18 is a third std::set of pointers: no row of the unit reads it besides the
//            constructor and destructor, so only "std::set of a pointer type" is proven (every std::set<T*> shares the
//            0064b2a0 / 0064b230 bodies): it is declared with Primitive* and named for its offset until a reader is
//            found (open question in the recorder's PROPOSALS).
//            Each std::set is 0x20 bytes under these flags (VS2008 RTM _SECURE_SCL).
#include <set>
#include "v8world/IWorldStage.h"

struct NativeAppUnit668Layout;

namespace RBX
{
	class Assembly;
	class Edge;
	class Joint;
	class Primitive;
	class World;

	class TreeStage : public IWorldStage
	{
		friend struct ::NativeAppUnit668Layout; // tests/record_native_app_unit668.py offset probes

	private:
		int maxTreeDepth;                       // +0x10
		bool dirty;                             // +0x14
		std::set<Primitive*> set18;             // +0x18 (only the pointer-set shape is proven)
		std::set<Assembly*> assemblies;         // +0x38
		std::set<Edge*> edges;                  // +0x58

		void dirtyAssembly(Assembly* a)         // inline: the insert argument is the helper's own parameter copy,
		{                                       // stored only after the NULL test in 00669240 / 006691e0
			assemblies.insert(a);
			dirty = true;
		}
		void dirtyAssemblies(Joint* j);         // 00669240

	public:
		TreeStage(IStage* upstream, World* world);          // 00669870 (needs a 2008 AssemblyStage: not built)
		~TreeStage();                                       // 00669390

		virtual StageType getStageType();                   // slot 1 (005e2790; not built, see the recorder)
		virtual void stepWorld(int worldStepId, int uiStepId, bool throttling);   // slot 2 (00669780)
		virtual void onEdgeAdded(Edge* e);                  // slot 4 (00669c00; not built)
		virtual void onEdgeRemoving(Edge* e);               // slot 5 (00669c70; not built)
		virtual int getMetric(MetricType metricType);       // slot 6 (00669030)

		void process();                                     // 00669410 (not built)
		void onPrimitiveAdded(Primitive* p);                // 00668d30 (ClumpStage::onPrimitiveAdded 0064cb0d)
		void onPrimitiveRemoving(Primitive* p);             // 00668d40 (ClumpStage 0064cc11)
	};
}
