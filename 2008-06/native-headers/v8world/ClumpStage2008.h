#pragma once
// 2008-06 native RBX::ClumpStage (inactive). Non-colliding path: the donor v8world/ClumpStage.h declares a much larger
// 2009-era class and is included by the donor v8world/World.h. A unit must not include both.
// Layout read from the 2008-06 binary:
//   size     0x30: JointStage(this, world) 00668470 news a ClumpStage with 0x30 bytes before calling 0064cfd0.
//   ctor     0064cfd0: downstream = new(0x78) TreeStage(this, world) 00669870, upstream +0x4, downstream +0x8,
//            world +0xc, vftable 0084b14c, then the std::set<T*> constructor 0064b2a0 at +0x10.
//   dtor     0064cf50: vftable store, std::set<T*> destructor 0064b230 at +0x10, then the IStage body deletes the
//            downstream stage through its slot 0.
//   onPrimitiveAdded 0064cae0 / onPrimitiveAddedAnchor 0064cc40 / onPrimitiveRemovedAnchor 0064ccf0: putInStage the
//            primitive, forward to TreeStage::onPrimitiveAdded 00668d30 (or look up the joint with getJoint 0064ca60
//            for Joint type 9 / 5), then build a 0x88-byte Joint subclass (Joint ctor 006455c0, vftables 0084b0cc /
//            0084b10c) and push it through the downstream's slot 4 (onEdgeAdded). Not built: needs those Joint
//            subclass declarations.
#include <set>
#include "v8world/IWorldStage.h"
#include "AppUnit668/TreeStage.h"

namespace RBX
{
	class Primitive;
	class World;

	class ClumpStage : public IWorldStage
	{
	private:
		std::set<Primitive*> set10;                // +0x10 INFERRED: only the pointer-set shape is proven (constructor/destructor are the shared pointer-set bodies); no row of the recovered unit reads it

	public:
		ClumpStage(IStage* upstream, World* world); // 0064cfd0
		~ClumpStage();                              // 0064cf50

		virtual StageType getStageType();           // slot 1 (CLUMP_STAGE, folded constant)
		virtual void onEdgeAdded(Edge* e);          // slot 4 (0064cec0)
		virtual void onEdgeRemoving(Edge* e);       // slot 5 (0064cf10)
	};
}
