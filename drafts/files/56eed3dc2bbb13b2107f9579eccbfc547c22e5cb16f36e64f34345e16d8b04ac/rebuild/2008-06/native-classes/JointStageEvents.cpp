// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::JointStage primitive events (inactive): onPrimitiveAdded 006685b0 and onPrimitiveRemoving
// 00668850. Evidence in native-headers/v8world/JointStage2008.h; the other rows of the JointStage unit live in
// JointStage2008.cpp (same includes). Donor bodies: tools/rbxgs v8world/JointStage.cpp.
// ClumpStage::onPrimitiveAdded 0064cae0 / onPrimitiveRemoving 0064cbf0 are direct (non-virtual) calls on the downstream
// stage (+0x8); the donor v8world/ClumpStage.h only supplies their declarations here (its 0x1cc layout is not used).
// No RBXASSERT survives in these bodies (no Debugable::assertAction reads, no dynamic_cast in rbx_static_cast or
// IPipelined::downstreamOfStage), so the release-assert define is dropped as in RotateJointChannel.cpp.
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
	void JointStage::onPrimitiveAdded(Primitive* p)
	{
		p->putInStage(this);
		rbx_static_cast<ClumpStage*>(getDownstream())->onPrimitiveAdded(p);

		std::vector<Joint*> moveJoints;

		typedef std::multimap<Primitive*, Joint*>::iterator Iterator;
		for (Iterator it = jointMap.lower_bound(p); it != jointMap.upper_bound(p); ++it)
		{
			Joint* j = it->second;
			Primitive* p0 = j->getPrimitive(0);
			Primitive* p1 = j->getPrimitive(1);
			if (p0->inPipeline() && p1->inPipeline() && p0->downstreamOfStage(this) && p1->downstreamOfStage(this))
				moveJoints.push_back(j);
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

	// 00668850: Primitive::getFirstJoint 005e7b90 / getNextJoint 005e7ba0, Joint slot 5 getJointType (ANCHOR_JOINT 5 /
	// FREE_JOINT 9 skipped), downstream slot 5 onEdgeRemoving, insertToListAndMap 00668340, ClumpStage::
	// onPrimitiveRemoving 0064cbf0, IPipelined::removeFromStage 00645840.
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
