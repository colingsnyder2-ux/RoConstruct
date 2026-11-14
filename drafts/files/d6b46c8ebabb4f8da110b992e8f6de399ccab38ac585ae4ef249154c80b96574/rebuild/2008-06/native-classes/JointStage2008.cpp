// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::JointStage (inactive); evidence in native-headers/v8world/JointStage2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows of the JointStage unit built here: edgeHasPrimitivesDownstream
// 00667f70, removeFromMap 00668280, insertToListAndMap 00668340, onEdgeAdded 006683b0, onEdgeRemoving 006683f0, the
// destructor 00668520 and the scalar deleting destructor 00668590 (vtable 0084cf64 is emitted here).
// Not built: the constructor 00668470 news a ClumpStage (0x30, 0064cfd0) and the donor v8world/ClumpStage.h declares a
// 0x1cc-byte class (see the recorder's PROPOSALS); onPrimitiveAdded 006685b0 / onPrimitiveRemoving 00668850 walk the
// primitive's edge lists through the native Primitive (not available).
// >>> native-status (generated) -- do not edit >>>
// JointStage2008 | 2008-06 | draft (no current byte proof)
// no original address mapped to this file yet | by -
// <<< native-status | src 5a55ec55 | roc native-status --write
#include "v8world/JointStage2008.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"
#include "util/RunningAverage.h"
#include "util/Math.h"

namespace RBX
{
#ifdef NATIVE_KERNEL_STAGES_PENDING
	// 007286a0 (folded `mov eax, 1`); needs the 2008 StageType (generated v8kernel/IStage.h).
	IStage::StageType JointStage::getStageType()
	{
		return JOINT_STAGE;
	}
#endif

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
	// Parked (hard-leftover lf14): 188 bytes, same calls (lower_bound 00667fd0, iterator ++ 0068dfa0, erase 005539d0) and
	// inline upper_bound; the only difference is that the original pushes esi in the prologue (ebx, ebp, esi, edi) while
	// this build sinks it after the lower_bound call. Rejected: the iterator declared in the for-init (adds an esi early
	// test, prologue changes), break instead of return (unchanged), postfix it++ (unchanged).
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

	// 00668af0 RunningAverageState::withinTolerance. Codegen analog placement: the original unit is the small
	// util/RunningAverage obj linked right after JointStage (rows 006689b0 Quaternion::maxComponent-shaped helper,
	// 00668a20 update, 00668af0 withinTolerance), which no assigned native file represents. Callees: Math::vector3Abs
	// 005de630, Math::maxAxisLength 005df220, Quaternion(const Matrix3&) 005dd570, maxComponent 006689b0 (all out
	// of line); the `> tolerance` tests are `test ah, 0x41; jne`. Donor body: tools/rbxgs util/RunningAverage.cpp.
	bool RunningAverageState::withinTolerance(const G3D::CoordinateFrame& cofm, float radius, float tolerance)
	{
		G3D::Vector3 deltaPos = Math::vector3Abs(this->position - cofm.translation);
		if (Math::maxAxisLength(deltaPos) > tolerance)
			return false;
		Quaternion deltaAngles = Quaternion(cofm.rotation) * radius;
		if ((this->angles - deltaAngles).maxComponent() > tolerance)
			return false;
		return true;
	}
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<RBX::Joint *> >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> > >;
template class std::_Tmap_traits<RBX::Primitive *,RBX::Joint *,std::less<RBX::Primitive *>,std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> >,1>;
template class std::_Tree<std::_Tmap_traits<RBX::Primitive *,RBX::Joint *,std::less<RBX::Primitive *>,std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> >,1> >;
template class std::_Tree<std::_Tset_traits<RBX::Joint *,std::less<RBX::Joint *>,std::allocator<RBX::Joint *>,0> >;
template class std::allocator<RBX::Joint *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Primitive *,RBX::Joint *,std::less<RBX::Primitive *>,std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> >,1> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<RBX::Joint *,std::less<RBX::Joint *>,std::allocator<RBX::Joint *>,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Primitive * const,RBX::Joint *> >;
