// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native RBX::JointStage (inactive); evidence in native-headers/v8world/JointStage2008.h.
// Verified by tests/record_native_kernel_stages.py. Rows of the JointStage unit built here: edgeHasPrimitivesDownstream
// 00667f70, removeFromMap 00668280, insertToListAndMap 00668340, onEdgeAdded 006683b0, onEdgeRemoving 006683f0, the
// destructor 00668520 and the scalar deleting destructor 00668590 (vtable 0084cf64 is emitted here).
// Constructor 00668470 (batch 27) against a unit-local copy of the 0x30-byte ClumpStage2008.h declaration; onPrimitiveAdded 006685b0 / onPrimitiveRemoving 00668850 walk the
// primitive's edge lists through the native Primitive (not available).
#include "v8world/JointStage2008.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"
#include "util/RunningAverage.h"
#include "util/Math.h"

namespace RBX
{
	// Unit-local copy of the ClumpStage declaration of native-headers/v8world/ClumpStage2008.h (that header includes the
	// native AppUnit658/Edge.h and AppUnit668/TreeStage.h, which collide with the donor v8world/Joint.h / Edge.h this
	// unit uses). Same members and order; only the constructor is called here.
	class ClumpStage : public IWorldStage
	{
	private:
		std::set<Edge*> set10;                       // +0x10 INFERRED: see ClumpStage2008.h

	public:
		ClumpStage(IStage* upstream, World* world); // 0064cfd0
		~ClumpStage();                              // 0064cf50

		virtual StageType getStageType();           // slot 1 (CLUMP_STAGE, folded constant)
		virtual void onEdgeAdded(Edge* e);          // slot 4 (0064cec0)
		virtual void onEdgeRemoving(Edge* e);       // slot 5 (0064cf10)
	};

	// 00668470 ??0JointStage@RBX@@QAE@PAVIStage@1@PAVWorld@1@@Z (registry, identity closure): new(0x30) ClumpStage(this,
	// world) 0064cfd0 as the downstream before the IStage fields (upstream +0x4, downstream +0x8, world +0xc), then the
	// set _Tree ctor 0064b2a0 (+0x10) and the multimap _Tree ctor 00446110 (+0x30). Donor JointStage.cpp shape.
	JointStage::JointStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new ClumpStage(this, world), world)
	{
	}

	// 007286a0 (folded `mov eax, 1`): JOINT_STAGE of the 2008 StageType (opt-in native-headers/kernel-stages v8kernel/IStage.h
	// through the native-flags line).
	IStage::StageType JointStage::getStageType()
	{
		return JOINT_STAGE;
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
	// Byte-identical (batch 41) with the 2007 openrbx statement shape (tools/openrbx JointStage.cpp: do { if (p == NULL)
	// break; ...; } while (0) with a JointMap::iterator declared before the for); this keeps esi pushed in the prologue.
	// Earlier rejected (lf14): `if (p) { Iterator it; for (...) }` (esi push sunk after the lower_bound call), the
	// iterator in the for-init, break instead of return, postfix it++. Batch 41 rejected: calling the base tree's
	// lower_bound directly (inlined, 199 B). The call 006682a1 reaches the JointStage2008.h noinline JointMap wrapper,
	// whose 54-byte body is identical to the COMDAT-folded _Tree::lower_bound 00667fd0.
	void JointStage::removeFromMap(Joint* j, Primitive* p)
	{
		do {
			if (p == NULL)
				break;
			JointMap::iterator pos;
			for (pos = jointMap.lower_bound(p); pos != jointMap.upper_bound(p); ++pos)
			{
				if (pos->second == j)
				{
					jointMap.erase(pos);
					return;
				}
			}
		} while (0);
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
	// /fp:fast (file flags) is required: without it the build is 218 bytes (spilled Quaternion temps, fcompp/test ah,5);
	// the integer JointStage rows above stay exact under /fp:fast.
	// 00668a20 (registry placeholder func_00668a20; `ret 8`, callers SleepStage::computeShouldSleep 0064a6c0 at 0064a70e):
	// donor RunningAverageState::update (tools/rbxgs util/RunningAverage.cpp), same placement note as withinTolerance
	// below. Constants 0.25f 0083a3e4 / 0.75f 0082f840, Quaternion(const Matrix3&) 005dd570, Quaternion::operator=
	// 005dd550 (out of line). PARKED near miss (197 bytes both; first divergence 00668a7d): after the Quaternion(Matrix3)
	// call the target loads the scale first (`fld [esp+0x38]; fld st(0); fmul [eax]`), this build loads q.x first
	// (`fld [eax]; fld [esp+0x38]; fmul st(1), st(0)`). Rejected: a named Quaternion with operator*= (222 B), operator*=
	// on the temporary (212 B), and a scratch util/Quaternion.h whose operator*(float) multiplies `fNum * x` (unchanged).
	void RunningAverageState::update(const G3D::CoordinateFrame& cofm, float radius)
	{
		this->position = this->position * 0.75f + cofm.translation * 0.25f;
		this->angles = this->angles * 0.75f + Quaternion(cofm.rotation) * (radius * 0.25f);
	}

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
