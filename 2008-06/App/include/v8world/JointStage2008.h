#pragma once
// >>> native-status (generated) -- do not edit >>>
// JointStage2008 | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src a4c99017 | roc native-status --write
// 2008-06 native RBX::JointStage (inactive). Declared under a non-colliding name: the original path
// v8world/JointStage.h is included by the donor v8world/World.h, so a header at that path would shadow the donor for
// every unit that includes World.h. A unit must not include both this header and the donor v8world/JointStage.h (or
// World.h). Bases IStage / IWorldStage are the donor headers (see CleanStage2008.h).
// Every JointStage field, slot and size below is read from the 2008-06 binary:
//   RTTI     JointStage 0084cf64 -> IWorldStage -> IStage (all mdisp 0).
//   slots    7: 0 scalar deleting dtor (00668590, calls ~JointStage 00668520), 1 getStageType (007286a0 `mov eax, 1`),
//            2 / 3 IStage::stepWorld / getKernel (0064a380 / 0064a390), 4 onEdgeAdded (006683b0), 5 onEdgeRemoving
//            (006683f0), 6 IWorldStage::getMetric (0064a3d0).
//   size     0x50 (CleanStage() 0064a310 news 0x50 for JointStage(this, world) 00668470).
//   ctor     00668470: downstream = new ClumpStage(this, world) (0x30, 0064cfd0), upstream +0x4, world +0xc; the _Tree
//            constructor 0064b2a0 (set) at +0x10, the _Tree constructor 00446110 (multimap) at +0x30.
//   dtor     00668520: vtable store, ~_Tree 00553d80 at +0x30, ~_Tree 0064b230 at +0x10, then the donor ~IStage body.
//   fields   incompleteJoints +0x10 (std::set<Joint*>: onEdgeRemoving 006683f0 erases the edge from +0x10 with the
//            set erase-by-key 005e9f60, 00668340 inserts it with the set insert 005e8c40), jointMap +0x30
//            (std::multimap<Primitive*, Joint*>: the evidence name of the insert 00668210 called by 00668340 on +0x30).
//            Each container is 0x20 bytes under these flags (VS2008 RTM _SECURE_SCL).
#include <set>
#include <map>
#include "v8world/IWorldStage.h"

struct NativeKernelStagesLayout;

namespace RBX
{
	class Joint;
	class Primitive;
	class Edge;
	class World;

	class JointStage : public IWorldStage
	{
		friend struct ::NativeKernelStagesLayout; // tests/NativeKernelStagesLayout.cpp offset asserts

	private:
		std::set<Joint*> incompleteJoints;                // +0x10
		std::multimap<Primitive*, Joint*> jointMap;       // +0x30

	private:
		bool edgeHasPrimitivesDownstream(Edge* e);        // 00667f70
		void insertToListAndMap(Edge* e);                 // 00668340 (analog name: set insert + one map insert per
		                                                  // non-NULL primitive)
		void removeFromMap(Joint* j, Primitive* p);       // 00668280

	public:
		JointStage(IStage* upstream, World* world);       // 00668470 (needs a ClumpStage declaration: PENDING)
		~JointStage();                                    // 00668520

		virtual StageType getStageType();                 // slot 1 (007286a0; NATIVE_KERNEL_STAGES_PENDING)
		virtual void onEdgeAdded(Edge* e);                // slot 4 (006683b0)
		virtual void onEdgeRemoving(Edge* e);             // slot 5 (006683f0)
		void onPrimitiveAdded(Primitive* p);              // 006685b0 (not built)
		void onPrimitiveRemoving(Primitive* p);           // 00668850 (not built)
	};
}
