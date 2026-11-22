// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::JointStage primitive events (inactive).
#undef _RELEASEASSERT
#include "v8world/JointStage2008.h"
#include "v8world/ClumpStage.h"
#include "v8world/Primitive.h"
#include "v8world/Joint.h"
#include <vector>

namespace RBX
{
	// 006685b0: IPipelined::putInStage 00645830, ClumpStage::onPrimitiveAdded 0064cae0, jointMap (+0x30)
	// lower_bound / upper_bound inline, vector<Joint*>::push_back 004213a0, incompleteJoints (+0x10) erase by key
	// (equal_range 004ad8b0 + erase range 0064ad30), removeFromMap 00668280, downstream slot 4 onEdgeAdded.
	// PARKED (3 hypotheses): 667 vs 671 bytes. Remaining diff: the target keeps `this` in edi (candidate ebx) and in the
	// first downstreamOfStage test calls this->getStageType() before p0's stage (spilling it to [esp + 0xc]), while the
	// second test calls p1's stage first, the order of the edgeHasPrimitivesDownstream 00667f70 body. Most likely the
	// original called edgeHasPrimitivesDownstream(it->second) and it was inlined in the original single unit; that
	// member is defined out of line in JointStage2008.cpp and cannot be repeated here.
	// Batch 25 rejected: this body moved into JointStage2008.cpp (static_cast, condition through
	// edgeHasPrimitivesDownstream(it->second)): 703 B, the multimap lower_bound / upper_bound stay out of line there
	// (the target expands them, 006685ff..) and the frame grows by 0x10. The same one-expansion stage-type evaluation-order
	// flip keeps SleepStage::changeAssemblyState 0064ae90 from matching (see SleepStage2008.cpp).
	void JointStage::onPrimitiveAdded(Primitive* p)
	{
		p->putInStage(this);
		rbx_static_cast<ClumpStage*>(getDownstream())->onPrimitiveAdded(p);

		std::vector<Joint*> moveJoints;

		typedef std::multimap<Primitive*, Joint*>::iterator Iterator;
		// Batch 36 rejected (target computes both bounds once before the loop, 006685ff..0066866c, `cmp [esp + 0x1c], ebx`
		// per pass): jointMap.equal_range(p) (619 B, equal_range called out of line) and lower_bound / upper_bound into
		// two locals before the loop (659 B, upper_bound inline but lower_bound 00667fd0 still called out of line).
		// Batch 37: the tree lower_bound is now called through Base:: (the noinline JointMap::lower_bound wrapper had kept it
		// out of line), so both bounds expand inline and the body builds to 667 B against 671. Remaining diff: `this` in ebx
		// (target edi) and the first downstreamOfStage test still evaluated p0's stage first (target this first with the
		// [esp + 0xc] spill, 006686c2..006686df), hence the 4-byte frame-slot shift. Batch 37 rejected: the body moved into
		// JointStage2008.cpp with an inline edgeHasPrimitivesDownstream(it->second) condition (735 B, frame 0x50, EH state
		// push order differs), and a file-local inline copy of the edgeHasPrimitivesDownstream body here (unchanged, 667 B).
		// The tree's lower_bound is expanded inline here (006685ff..00668637), so the call bypasses the noinline
		// JointMap::lower_bound wrapper of JointStage2008.h (that wrapper is removeFromMap's call 006682a1).
		for (Iterator it = jointMap.JointMap::Base::lower_bound(p); it != jointMap.upper_bound(p); ++it)
		{
			// The iterator is checked and dereferenced twice (00668694 and 0066870c): once for the test (the
			// edgeHasPrimitivesDownstream 00667f70 condition, inline here) and again for push_back(it->second).
			Joint* j = it->second;
			Primitive* p0 = j->getPrimitive(0);
			Primitive* p1 = j->getPrimitive(1);
			if (p0->inPipeline() && p1->inPipeline() && p0->downstreamOfStage(this) && p1->downstreamOfStage(this))
				moveJoints.push_back(it->second);
		}

		for (size_t i = 0; i < moveJoints.size(); ++i)
		{
			Joint* j = moveJoints[i];
			incompleteJoints.erase(j);
			removeFromMap(j, j->getPrimitive(0));
			removeFromMap(j, j->getPrimitive(1));
			getDownstreamWS()->onEdgeAdded(j);
		}
	}

	void JointStage::onPrimitiveRemoving(Primitive* p)
	{
		std::vector<Joint*> moveJoints;

		for (Joint* j = p->getFirstJoint(); j; j = p->getNextJoint(j))
		{
			if (j->getJointType() != Joint::ANCHOR_JOINT && j->getJointType() != Joint::FREE_JOINT && j->downstreamOfStage(this))
				moveJoints.push_back(j);
		}

		for (size_t i = 0; i < moveJoints.size(); ++i)
		{
			Joint* j = moveJoints[i];
			getDownstreamWS()->onEdgeRemoving(j);
			insertToListAndMap(j);
		}

		rbx_static_cast<ClumpStage*>(getDownstream())->onPrimitiveRemoving(p);
		p->removeFromStage(this);
	}
}
