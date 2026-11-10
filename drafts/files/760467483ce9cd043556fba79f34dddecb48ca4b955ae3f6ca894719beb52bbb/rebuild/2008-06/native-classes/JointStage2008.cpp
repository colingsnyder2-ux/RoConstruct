// 2008-06 native RBX::JointStage (inactive); evidence in native-headers/v8world/JointStage2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows of the JointStage unit built here: edgeHasPrimitivesDownstream
// 00667f70, removeFromMap 00668280, insertToListAndMap 00668340, onEdgeAdded 006683b0, onEdgeRemoving 006683f0, the
// destructor 00668520 and the scalar deleting destructor 00668590 (vtable 0084cf64 is emitted here).
// Not built: the constructor 00668470 news a ClumpStage (0x30, 0064cfd0) and the donor v8world/ClumpStage.h declares a
// 0x1cc-byte class (see the recorder's PROPOSALS); onPrimitiveAdded 006685b0 / onPrimitiveRemoving 00668850 walk the
// primitive's edge lists through the native Primitive (not available).
#include "v8world/JointStage2008.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"

namespace RBX
{
	// 007286a0 (folded `mov eax, 1`); JOINT_STAGE is 1 in 2008.
	IStage::StageType JointStage::getStageType()
	{
		return (IStage::StageType)1;
	}

	// 00668520
	JointStage::~JointStage()
	{
	}

	// 00667f70
	bool JointStage::edgeHasPrimitivesDownstream(Edge* e)
	{
		Primitive* p0 = e->getPrimitive(0);
		Primitive* p1 = e->getPrimitive(1);
		if (p0->inPipeline() && p1->inPipeline() && p0->downstreamOfStage(this) && p1->downstreamOfStage(this))
			return true;
		return false;
	}

	// 00668340
	void JointStage::insertToListAndMap(Edge* e)
	{
		Joint* j = rbx_static_cast<Joint*>(e);
		incompleteJoints.insert(j);
		if (Primitive* p0 = j->getPrimitive(0))
			jointMap.insert(std::make_pair(p0, j));
		if (Primitive* p1 = j->getPrimitive(1))
			jointMap.insert(std::make_pair(p1, j));
	}

	// 00668280
	void JointStage::removeFromMap(Joint* j, Primitive* p)
	{
		if (p)
		{
			typedef std::multimap<Primitive*, Joint*>::iterator Iterator;
			Iterator it;
			for (it = jointMap.lower_bound(p); it != jointMap.upper_bound(p); ++it)
			{
				if (it->second == j)
				{
					jointMap.erase(it);
					return;
				}
			}
		}
	}

	// 006683b0
	void JointStage::onEdgeAdded(Edge* e)
	{
		e->putInStage(this);
		if (edgeHasPrimitivesDownstream(e))
			getDownstreamWS()->onEdgeAdded(e);
		else
			insertToListAndMap(e);
	}

	// 006683f0
	void JointStage::onEdgeRemoving(Edge* e)
	{
		if (e->downstreamOfStage(this))
		{
			getDownstreamWS()->onEdgeRemoving(e);
		}
		else
		{
			Joint* j = rbx_static_cast<Joint*>(e);
			incompleteJoints.erase(j);
			removeFromMap(j, j->getPrimitive(0));
			removeFromMap(j, j->getPrimitive(1));
		}
		e->removeFromStage(this);
	}
}
