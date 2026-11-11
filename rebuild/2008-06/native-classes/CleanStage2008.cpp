// 2008-06 native RBX::CleanStage (inactive); evidence in native-headers/v8world/CleanStage2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows of the CleanStage unit (0064a310..0064a510): the constructor
// 0064a310, the header-inline COMDATs IStage::stepWorld 0064a380 / IStage::getKernel 0064a390, the scalar deleting
// destructor 0064a3a0 (vtable 0084b05c is emitted here), onPrimitiveAdded 0064a3e0, onPrimitiveRemoving 0064a400,
// onJointPrimitiveNulling 0064a420, onJointPrimitiveSet 0064a460, onEdgeAdded 0064a4d0, onEdgeRemoving 0064a510.
// The IPipelined calls bind to the 2008 bodies: putInPipeline 00645830 (`currentStage = stage`, shared with
// putInStage / putInKernel), removeFromPipeline 00645820 (`currentStage = NULL`).
// >>> native-status (generated) -- do not edit >>>
// CleanStage2008 | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 67b9edf4 | roc native-status --write
#include "v8world/CleanStage2008.h"
#include "v8world/JointStage2008.h"
#include "v8world/Primitive.h"

namespace RBX
{
	// 0064a310
	CleanStage::CleanStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new JointStage(this, world), world)
	{
	}

#ifdef NATIVE_KERNEL_STAGES_PENDING
	// 00416690 (folded `xor eax, eax`); needs the 2008 StageType (generated v8kernel/IStage.h).
	IStage::StageType CleanStage::getStageType()
	{
		return CLEAN_STAGE;
	}
#endif

	// 0064a3e0
	void CleanStage::onPrimitiveAdded(Primitive* p)
	{
		p->putInPipeline(this);
		getJointStage()->onPrimitiveAdded(p);
	}

	// 0064a400
	void CleanStage::onPrimitiveRemoving(Primitive* p)
	{
		getJointStage()->onPrimitiveRemoving(p);
		p->removeFromPipeline(this);
	}

	// 0064a420
	void CleanStage::onJointPrimitiveNulling(Joint* j, Primitive* nulling)
	{
		if (j->downstreamOfStage(this))
			getDownstreamWS()->onEdgeRemoving(j);
	}

	// 0064a460
	void CleanStage::onJointPrimitiveSet(Joint* j, Primitive* p)
	{
		if (j->getPrimitive(0) && j->getPrimitive(1) && j->getPrimitive(0) != j->getPrimitive(1))
		{
			if (!j->downstreamOfStage(this))
				getDownstreamWS()->onEdgeAdded(j);
		}
		else
		{
			if (j->downstreamOfStage(this))
				getDownstreamWS()->onEdgeRemoving(j);
		}
	}

	// 0064a4d0
	void CleanStage::onEdgeAdded(Edge* e)
	{
		e->putInPipeline(this);
		if (e->getPrimitive(0) && e->getPrimitive(1) && e->getPrimitive(0) != e->getPrimitive(1))
			getDownstreamWS()->onEdgeAdded(e);
	}

	// 0064a510
	void CleanStage::onEdgeRemoving(Edge* e)
	{
		if (e->downstreamOfStage(this))
			getDownstreamWS()->onEdgeRemoving(e);
		e->removeFromPipeline(this);
	}
}
